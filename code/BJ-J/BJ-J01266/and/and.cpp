#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], mxsiz, ans, st;
bool alive[N];
string s[N];
string _string2(int x)
{
    string res = "", res1 = "";
    while (x)
    {
        if (x & 1) res += '1';
        else res += '0';
        x >>= 1;
    }
    for (int i = 0; i < res.size(); i++) res1 += res[res.size() - i - 1];
    return res1;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    st = -1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        alive[i] = 1;
        s[i] = _string2(a[i]);
        mxsiz = max(mxsiz, (int)s[i].size());
    }
    for (int i = 1; i <= n; i++)
    {
        int siz = s[i].size();
        for (int j = 1; j <= mxsiz - siz; j++) s[i] = '0' + s[i];
    }
    for (int i = 0; i < mxsiz; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += (s[j][i] == '1');
        if (cnt >= m)
        {
            st = i;
            break;
        }
    }
    if (st == -1)
    {
        cout << 0;
        return 0;
    }
    for (int i = st; i < mxsiz; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!alive[j]) continue;
            cnt += (s[j][i] == '1');
            alive[j] = (s[j][i] == '1');
        }
        if (cnt >= m) ans += (1 << (mxsiz - i - 1));
        else break;
    }
    cout << ans;
    return 0;
}
