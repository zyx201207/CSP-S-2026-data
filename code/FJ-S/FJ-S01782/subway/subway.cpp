#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
using namespace std;
int c,n,m,d,q;
const int N=510,M=5e5+10,D=22;
int w[M];
vector<int> op[M],t[M];
ll f[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,ts;
            cin>>a>>ts;
            op[a].pb(i);
            t[a].pb(ts);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<sz(op[i]);j++)
        {
            for(int k=j+1;k<sz(op[i]);k++)
            {
                f[op[i][j]][op[i][k]]=min(f[op[i][j]][op[i][k]],1ll*t[i][j]+t[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[j][i]);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++) clog<<f[i][j]<<' ';
    //     clog<<endl;
    // }
    while(q--)
    {
        int x,y;
        ll ans=1e18;
        cin>>x>>y;
        for(int i=0;i<sz(op[x]);i++)
        {
            for(int j=0;j<sz(op[y]);j++)
            {
                // clog<<i<<' '<<j<<endl;
                ans=min(ans,f[op[x][i]][op[y][j]]+w[x]+w[y]+t[x][i]+t[y][j]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}