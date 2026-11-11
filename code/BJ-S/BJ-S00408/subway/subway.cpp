#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=5e5+5;
const int maxn=505;
const int maxq=1e5+5;
ll C,n,m,d,Q;
ll w[maxm];
ll k[maxn];
vector<ll> a[maxn],t[maxn];
struct node
{
    ll s,e,id;
} q[maxq];
bool cmp(node x,node y)
{
    if(x.s!=y.s)
    {
        return x.s<y.s;
    }
    return x.e<y.e;
}
ll ans[maxq];
ll dis[maxm],vis[maxm];
struct Node
{
    ll x,d;
};
bool operator <(Node x,Node y)
{
    return x.d>y.d;
}
vector<pair<ll,ll> > g[maxm];
void dij(ll st)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[st]=0;
    priority_queue<Node> q;
    q.push({st,0});
    while(!q.empty())
    {
        Node cur=q.top();q.pop();
        if(vis[cur.x])continue;
        vis[cur.x]=1;
        for(auto i:g[cur.x])
        {
            if(vis[i.first])continue;
            if(dis[i.first]>cur.d+i.second)
            {
                dis[i.first]=cur.d+i.second;
                q.push({i.first,dis[i.first]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
        for(int j=0;j<k[i];j++)
        {
            for(int ij=j+1;ij<k[i];ij++)
            {
                g[a[i][j]].push_back({a[i][ij],t[i][j]+t[i][ij]});
                g[a[i][ij]].push_back({a[i][j],t[i][j]+t[i][ij]});
            }
        }
    }
    for(int i=1;i<=Q;i++)
    {
        cin>>q[i].s>>q[i].e;
        q[i].id=i;
    }
    sort(q+1,q+Q+1,cmp);
    ll i=1;
    while(i<=Q)
    {
        ll cur=q[i].s;
        dij(cur);
        while(q[i].s==cur)
        {
            ans[q[i].id]=dis[q[i].e]+w[q[i].s]+w[q[i].e];
            i++;
        }
    }
    for(int i=1;i<=Q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
