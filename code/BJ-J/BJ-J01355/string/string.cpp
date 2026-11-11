#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans = 0,a[200010],k;
string s = " ";
char c[200010];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        if(i == 1) k = a[i];
        k = __gcd(a[i],k);
    }
    if(k != 1)
    {
        for(int i = 1;i <= n;i++) a[i] /= k;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= a[i];j++) s = s + c[i];
    }
    for(int i = 1;i <= s.size() / 2;i++)
    {
        if(s[i] != s[s.size() - i]) ans++;
    }
    cout << ans * k;
    return 0;
}