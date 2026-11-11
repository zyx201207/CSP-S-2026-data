#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
pair<int, char> a[N];
void solve1(int n)
{
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= a[i].first; j++)
        {
            s += a[i].second;
        }
    }
    long long l = 0, r = s.size() - 1;
    long long ans = 0;
    for ( ; l <= r; l++, r--)
    {
        if (s[l] != s[r]) ans++;
    }
    cout << ans;
    return;
}
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }
    solve1(n);
    return 0;
}
