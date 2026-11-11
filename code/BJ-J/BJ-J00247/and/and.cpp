#include <bits/stdc++.h>
using namespace std;
const long long N = 25, M = 2e5 + 10;
bool vis[N]; long long a[M];
void input(long long n, long long m)
{
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    return;
}
long long ans = 0;
vector<long long> x;
void dfs(long long n, long long m, long long now, long long me)
{
    if (x.size() == m)
    {
        long long lans = a[x[0]];
        for (long long i = 1 ; i < x.size(); i++)
        {
            lans &= a[x[i]];
        }
        ans = max(ans, lans);
        return;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        x.push_back(i);
        dfs(n, m, now + 1, i);
        x.pop_back();
    }
}

void solve1(long long n, long long m)
{
    for (long long i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        x.clear();
        vis[i] = 1;
        x.push_back(i);
        dfs(n, m, 1, i);
    }
    cout << ans;
    return;
}
pair<long long, long long> b[M];
bool cmp(pair<long long, long long> x, pair<long long, long long> y)
{
    if (x.second != y.second) return x.second > y.second;
    long long a = 0, b = 0;
    pair<long long, long long> xx = x, yy = y;
    while (xx.first % 2 == 0 && xx.first) {a++, xx.first /= 2;}
    while (yy.first % 2 == 0 && yy.first) {b++, yy.first /= 2;}
    return a > b;
}
void solve2(long long n, long long m)
{
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        long long cnt = 0;
        long long xx = x;
        while (x)
        {
            if (x % 2 == 1) cnt++;
            x /= 2;
        }
        b[i] = {xx, cnt};
    }
    sort(b + 1, b + n + 1, cmp);
    long long ans = b[1].first;
    for (long long i = 1; i <= m; i++)
    {
        //cout << b[i].first << "," << b[i].second << '\n';
        ans &= b[i].first;
    }
    cout << ans;
    return;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n, m; cin >> n >> m;
    if (n <= 20)
    {
        input(n, m);
        solve1(n, m);
    } else {
        solve2(n, m);
    }
    return 0;
}
