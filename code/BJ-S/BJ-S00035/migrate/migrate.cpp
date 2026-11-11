#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn=2e6+5;
struct node
{
    ll x,dep;
};
ll c,t;
ll n,d;
ll x[maxn];
//map<pair<int,int>,int> dist,distn;
vector<int> g[maxn];
int bfs(int u,int v)
{
    //if(dist.find({u,v})!=dist.end())return dis[{u,v}];
    int mndp=INT_MAX,mnx=0;
    deque<node> q;
    q.push_back({u,1});
    while(!q.empty())
    {
        auto now=q.front();
        if(now.x==v)
        {
            /*if(now.dep<mndp)
            {
                mndp=now.dep;
                mnx=0;
            }
            if(now.dep==mndp)mnx++;*/
            if(now.dep>mndp)break;
            mndp=now.dep;
            mnx++;
        }
        q.pop_front();
        for(int son:g[now.x])
        {
            //dist[{u,v}]=1;
            q.push_back({son,now.dep+1});
            //if(u==1&&v==5)cout<<now.x<<' '<<son<<endl;
        }
    }
    //cout<<u<<' '<<v<<' '<<mndp<<' '<<mnx<<endl;
    if(mnx==2)return 1;
    else return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        if(c<=10)
        {
            ll ans=0;
            for(int i=1;i<=n;i++)g[i].clear();
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>x[i];
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(x[j]-x[i]<=d)g[i].push_back(j);
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                    ans+=bfs(i,j);
            }
            cout<<ans<<'\n';
        }
        if(c==11||c==12)
        {
            ll ans=0;
            for(int i=1;i<=n;i++)g[i].clear();
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>x[i];
            int gc=d/(x[2]-x[1]);
            ans+=n-2*gc+1;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
