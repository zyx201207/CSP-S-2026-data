#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 12;
int n;
long long d;
long long x[MAXN];
int p[MAXN];
long long f[MAXN][3];
void work()
{
    cin >> n >> d;
    for (int i=1;i<=n;i++) cin >> x[i];
    for (int i=n,j=n;i>=1;i--)
    {
        while (x[j]-x[i]>d) j --;
        p[i] = j;
    }
    for (int i=0;i<=n+1;i++) f[i][0] = f[i][1] = f[i][2] = 0;
    p[0] = -1e9;
    for (int i=1;i<=n;i++)
    {
        if (p[i]==i) continue ;
        f[p[i]][0] ++;
        if (i>2&&p[i-2]==p[i]) continue ;
        if (p[i-1]==p[i])
        {
            f[p[i]][2] += f[i][0];
        }
        else if (p[i-1]==p[i]-1)
        {
            f[p[i]][2] += f[i][2];
            f[p[i]][1] += f[i][0] + f[i][1];
        }
        else 
        {
            f[p[i]][2] += f[i][2];
            f[p[i]][0] += f[i][0] + f[i][1];
        }
    }
    long long ans = 0;
    for (int i=2;i<=n;i++)
    {
        if (i==p[i]) continue ;
        int l = i+1,r = p[i];
        if (i>2) l = max(l,p[i-2]+1);
        int t = p[i-1];
        // cerr << i << ' ' << ans << ' ';
        if (t<r) ans += (r-t)*f[i][2];
        if (l<=t) ans += (t-l+1)*f[i][0];
        // cerr << ans << endl;
    }
    cout << ans << '\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int c,t;
    cin >> c >> t;
    while (t--) work();
    return 0;
}