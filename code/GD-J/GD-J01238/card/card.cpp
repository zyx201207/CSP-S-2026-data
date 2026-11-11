#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n, m, a[500005];
map<int, int> cnt;
string s;
signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
    {
        s = to_string(a[j]);
        for (int i = j + 1; i <= n; i++)
        {
            if (s.find(a[i] + '0') != string::npos)
                s = s.substr(0, s.find(a[i] + '0'));
            s = s + to_string(a[i]);
        }
        for (int i = 0; i < s.size(); i++)
            cnt[(s[i] - '0')]++;
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << " ";
    cout << endl;
    return 0;
}