#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
char c[200005];
string s;
int L, cnt;
bool same = 1;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    if (n == 1) cout << 0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        cin >> c[i];
        for (int j=1;j<=a[i];j++ ) s += c[i];
        c[0] = c[1];

        if (c[i] != c[i-1])
            same = false;
        L += a[i];
    }
    if (same == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i=0;i<L / 2;i++)
    {
        if (s[i] != s[L+1] - i) cnt++;
    }
    cout << cnt;
    return 0;
}

