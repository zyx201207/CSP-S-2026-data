#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=5e5+5;
ll c,n,m,d,q,w[N],k[N],dis[N],fst[N];
int id=0;
struct aa{
    int u,id;
    ll w;
}a[N];
vector<aa> g[N];
void dij(int st)
{
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0,id=0;
    int cnt=0,lid=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,st});
    while(!q.empty())
    {
        auto t=q.top();
        q.pop();
        int u=t.second;
        ll d=t.first;
        if(d>dis[u])
        continue;
        for(auto e:g[u])
        {
            int v=e.u;
            ll w=e.w;
            int idd=e.id,ex=0;
            cnt++;
            if(cnt==1)
            {
                id=e.id;
                lid=e.id;
            }
            if(lid!=idd)
            {
                ex=fst[idd];
            }
            if(dis[u]+w+ex<dis[v])
            {
                dis[v]=dis[u]+w+ex;
                
                q.push({dis[v],v});
            }
            lid=e.id;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a,last;
            ll t;
            cin>>a>>t;
            if(j==1)
            {
                fst[i]=t;
                last=a;
                continue;
            }
            g[last].push_back({a,i,t});
            g[a].push_back({last,i,t});
            last=a;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        dij(x);
        cout<<fst[id]+dis[y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
