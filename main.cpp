#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

// https://leetcode.com/problems/reorder-data-in-log-files/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isLetterLog(string &s) {
        return isalpha(s[s.find(' ') + 1]);
    }

    vector<string> reorderLogFiles(vector<string> &logs) {
        // put letters to end
        int j = logs.size() - 1;
        for (int i = logs.size() - 1; i >= 0; --i) {
            if (!isLetterLog(logs[i]))
                swap(logs[i], logs[j--]);
        }
        sort(logs.begin(), logs.begin() + j + 1,
             [&](const string &a, const string &b) -> bool {
                 int a1 = a.find(' ');
                 int b1 = b.find(' ');
                 string as = a.substr(a1);
                 string bs = b.substr(b1);
                 if (as == bs)
                     return a.substr(0, a1) < b.substr(0, b1);
                 else
                     return as < bs;
             });
        return logs;
    }
};

void test1() {
    vector<string> v1{"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};


    cout << "let1 art can,let3 art zero,let2 own kit dig,dig1 8 1 5 1,dig2 3 6 ?\n" << Solution().reorderLogFiles(v1)
         << endl;
}

void test2() {

}

void test3() {

}