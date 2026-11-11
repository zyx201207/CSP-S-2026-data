#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, pos[200005], ans;
char c[200005], nowl, nowr;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    pos[1] = 1;
    for (int i = 1; i <= n; i++) cin >> pos[i + 1] >> c[i], pos[i + 1] += pos[i];
    vector<pair<int, char>> s;
    int l = 1, r = n + 1;
    while (l <= r)
    {
        if (pos[l] <= pos[n + 1] - pos[r] + 1) s.push_back(make_pair(pos[l], c[l])), l++;
        else s.push_back(make_pair(pos[r] - pos[n + 1] - 1, c[r - 1])), r--;
    }
    for (int i = 0; i < s.size(); i++)
    {
        // cout << s[i].first << ' ' << s[i].second << '\n';
        if (s[i].first < 0) nowr = s[i].second;
        else nowl = s[i].second;
        if (!nowl || !nowr) continue;
        ans += (abs(s[i + 1].first) - abs(s[i].first)) * (nowl != nowr);
        // cout << i << ' ' << nowl << ' ' << nowr << '\n';
    }

    cout << ans << '\n';
    return 0;
}
/*
2
2 a
3 a
*/
// 09:52