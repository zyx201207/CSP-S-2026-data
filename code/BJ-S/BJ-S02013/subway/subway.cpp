#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
vector<pii>sta[N];
int dis[510][510];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k; cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            sta[x].pb(mp(i,y));
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int sz=sta[i].size();
        for(int j=0;j<sz;j++)
        {
            for(int k=j+1;k<sz;k++)
            {
                int tmp=min(sta[i][j].sc+sta[i][k].sc,dis[sta[i][j].fr][sta[i][k].fr]);
                dis[sta[i][j].fr][sta[i][k].fr]=tmp;
                dis[sta[i][k].fr][sta[i][j].fr]=tmp;
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
    while(q--)
    {
        int x,y,ans=1e18;
        cin>>x>>y;
        int sx=sta[x].size(),sy=sta[y].size();
        for(int i=0;i<sx;i++)
            for(int j=0;j<sy;j++)
                ans=min(ans,sta[x][i].sc+sta[y][j].sc+dis[sta[x][i].fr][sta[y][j].fr]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}