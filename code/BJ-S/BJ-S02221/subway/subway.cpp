#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];vector<pii> a[M];ll dis[N][N];
int main()
{
    freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        for(int j=1,v,t;j<=x;j++)
        {
            cin>>v>>t;
            a[v].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<a[i].size();j++) for(int k=j+1;k<a[i].size();k++)
        {
            ll u=a[i][j].first,wu=a[i][j].second,v=a[i][k].first,wv=a[i][k].second;
            dis[u][v]=min(dis[u][v],wu+wv);
            dis[v][u]=min(dis[v][u],wu+wv);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
    {
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    //size<=d
    while(q--)
    {
        int x,y;cin>>x>>y;ll ans=LLONG_MAX;
        for(auto e1:a[x]) for(auto e2:a[y])
        {
            ans=min(ans,w[x]+e1.second+dis[e1.first][e2.first]+e2.second+w[y]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}