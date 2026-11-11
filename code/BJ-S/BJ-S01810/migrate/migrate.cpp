#include<bits/stdc++.h>
#define int long long
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e6+5;
int C,T;
int n,a[N],len[N],f[N],ans,d,nxt[N];
void dfs(int u,int w)
{
    if(len[u]<w)return;
    if(len[u]>w)
    {
        f[u]=0;
        len[u]=w;
    }
    f[u]++;
    for(int j=u+1;a[j]-a[u]<=d&&j<=n;j++)
    {
        dfs(j,w+1);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    faster;
    cin >> C >> T;
    while(T--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        if(C<=2)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    len[j]=n;f[j]=0;
                }
                dfs(i,0);
                for(int j=i+1;j<=n;j++)
                {
                    if(f[j]==2)
                    {
                        // cout << i <<' '<< j <<'\n';
                        ans++;
                    }
                }
            }
        }
        else if(C<=12)
        {
            int g=d/(a[2]-a[1]);
            if(g==2)
            {
                ans=max(0ll,n-3);
            }
            else if(g>=3)
            {
                ans=max(0ll,n-2*g+1);
            }
        }
        cout << ans <<'\n';
        ans=0;
    }
    return 0;
}