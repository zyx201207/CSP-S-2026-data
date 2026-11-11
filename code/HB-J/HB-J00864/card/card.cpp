#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <unordered_set>
#include <utility>
using namespace std;

int n, m;
deque<int> arr, pos, ans, foo, fini;
deque<int> cnt;
//unordered_map<int, deque<int>> cs;
//deque<unordered_set<int>> ds;
unordered_set<int> odds;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    arr.resize(n);
    pos.resize(n);
    ans.resize(m + 1);
    bool isa = true;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        //cs[arr[i]].push_back(i);
        if (i > 0 && arr[i - 1] > arr[i])
            isa = false;
    }
    foo = arr;
    if (isa) {
        cnt.resize(m + 1);
        fini.resize(m + 1);
        ans.assign(m + 1, 1);
        unique(foo.begin(), foo.end());
        for (int i = 0; i < n; ++i) {
            ++cnt[arr[i]];
            if (i < n - 1 && arr[i] != arr[i + 1])
                fini[arr[i]] = i;
        }
        fini[arr[n - 1]] = n - 1;
        for (int i = 0; i < n; ++i) {
            --cnt[arr[i]];
            if (cnt[arr[i]] == 0)
                foo.pop_front();
            for (int j = 0; j < foo.size(); ++j)
                ++ans[foo[j]];
        }
        for (int i = 1; i <= m; ++i)
            cout << ans[i] << ' ';
        return 0;
    }
    deque<pair<int, int>> ps;
    deque<bool> ff;
    for (int i = 0; i < n; ++i) {
        ff.assign(m + 1, false);
        for (int j = i; j < n; ++j) {
            for (int k = i; k < j; ++k) {
                bool tag = false;
                for (int t = 0; t < ps.size(); ++t)
                    if (k >= ps[t].first && k <= ps[t].second) {
                        k = ps[t].second;
                        tag = true;
                        break;
                    }
                if (tag)
                    continue;
                if (arr[k] == arr[j]) {
                    ps.push_back({k, j - 1});
                    break;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            bool tag = false;
            for (int k = 0; k < ps.size(); ++k)
                if (j >= ps[k].first && j <= ps[k].second) {
                    j = ps[k].second;
                    tag = true;
                    break;
                }
            if (tag)
                continue;
            if (!ff[arr[i]]) {
                ++ans[arr[i]];
                ff[arr[i]] = true;
            }
        }
        ff.clear();
        ps.clear();
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << ' ';
    return 0;
}