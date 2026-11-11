#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
int mp[N][N];
vector<array<int,2> >vec[M];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    memset(mp,0x3f,sizeof(mp));
    for(int i=1,k;i<=n;i++)
    {
        mp[i][i]=0;
        cin>>k;
        for(int j=1,a,t;j<=k;j++)
        {
            cin>>a>>t;
            vec[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto u:vec[i])
        {
            for(auto v:vec[i])
            {
                mp[u[0]][v[0]]=min(mp[u[0]][v[0]],u[1]+v[1]);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                mp[i][j]=mp[j][i]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int ans=1e17;
        for(auto u:vec[a])
        {
            for(auto v:vec[b])
            {
                ans=min(ans,mp[u[0]][v[0]]+u[1]+v[1]);
            }
        }
        cout<<ans+w[a]+w[b]<<'\n';
    }
    return 0;
}
