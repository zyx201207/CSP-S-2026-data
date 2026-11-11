#include <bits/stdc++.h>
using namespace std;
string s,sz,sf;
char c;
int ans,cnt,n,a,m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while(n--)
    {
        cin >> a >> c;
        m += a;
        while(a--) s = s + c;
    }
    s = " " + s;
    for(int i = 1; i <= m / 2; i++) sz[i] = s[i];
    for(int i = m; cnt <= m / 2; i--) sf[++cnt] = s[i];
    for(int i = 1; i <= m / 2; i++) if(sz[i] != sf[i]) ans++;
    cout << ans;
    return 0;
}
