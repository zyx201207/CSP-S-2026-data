#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=505,M=5e5+5,INF=1e18;
int c,n,m,d,q,k,x,y,aa,tt,ans;
int w[M],f[N][N];
struct node{
    int a,t;
};
vector <node> g[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>aa>>tt;
            g[aa].push_back(node{i,tt});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=INF;
    for(int i=1;i<=m;i++)
        for(auto x:g[i])
            for(auto y:g[i])
            {
                if(x.a==y.a) continue;
                f[x.a][y.a]=min(f[x.a][y.a],x.t+y.t);
                f[y.a][x.a]=min(f[y.a][x.a],x.t+y.t);
            }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        ans=INF;
        cin>>x>>y;
        for(auto xx:g[x])
            for(auto yy:g[y])
                ans=min(ans,f[xx.a][yy.a]+xx.t+yy.t);
        ans+=(w[x]+w[y]);
        cout<<ans<<"\n";
    }
    return 0;
}
