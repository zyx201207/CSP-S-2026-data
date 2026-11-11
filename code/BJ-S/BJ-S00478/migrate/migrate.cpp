#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int inf=0x3f3f3f3f3f3f3f3f;
int c,T;
int n,d,a[N];
int f[N],g[N];

void solve()
{
    cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++) f[j]=inf,g[j]=0;
        int p=i,tmp=1;
        f[i]=0,g[i]=1;
        for (int j=i+1;j<=n;j++)
        {
            while (p<=j&&a[j]-a[p]>d) tmp-=g[p++];
            if (p>j) break;
            if (tmp<=0) { tmp=0; for (int k=p;k<j&&f[k]==f[p];k++) tmp+=g[k]; }
            f[j]=f[p]+1,g[j]=tmp;
            if (g[j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>c>>T;
    while (T--) solve(); return 0;
}
//mj