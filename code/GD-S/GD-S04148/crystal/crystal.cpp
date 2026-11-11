#include <bits/stdc++.h>
using namespace std;
map<long long, int> cnt;
queue<std::map<long long, int>::iterator> que;
long long sumcnt, sum;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        cnt[a]++;
    }
    long long maxn = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        while (sumcnt * it->first - sum > m) // 大块的删除了
        {
            sumcnt -= que.front()->second;
            sum -= que.front()->first * que.front()->second;
            que.pop();
        }
        // 暴力补齐第一个块
        long long ans = sumcnt;
        if (que.size() && que.front() != cnt.begin())
        {
            long long mpy = m - sumcnt * it->first + sum;
            if (mpy > 0)
                ans += mpy / (it->first - prev(que.front())->first);
        }
        maxn = max(ans + it->second, maxn);
        que.push(it);
        sumcnt += it->second;
        sum += it->second * it->first;
    }
    cout << maxn;
    return 0;
}