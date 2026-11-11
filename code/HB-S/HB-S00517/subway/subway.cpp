#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
vector<pii> mp[1500006];
int c,n,m,d,q;
int cntnd;
struct cx
{
    int l,r,op;
}xxkan[100005];
int ans[100005];
bool cmp(cx qq,cx ww)
{
    return qq.l<ww.l;
}
int dis[1500006];
bitset<1500006> vis;
void dijkstra(int st)
{
    fill(dis+1,dis+cntnd+1,INF);
    vis=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,st});
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(auto qwq:mp[u])
        {
            int v=qwq.first,w=qwq.second;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(vis[v]==0) q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        mp[i].push_back({i+m,x});
        mp[i+m].push_back({i,x});
    }
    cntnd=2*m;
    for(int i=1;i<=n;i++)
    {
        int k,lst=0;
        cin>>k;
        while(k--)
        {
            int v,w;
            cin>>v>>w;
            cntnd++;
            mp[v+m].push_back({cntnd,w});
            mp[cntnd].push_back({v+m,w});
            if(lst) mp[lst].push_back({cntnd,0}),mp[cntnd].push_back({lst,0});
            lst=cntnd;
        }
    }
    // for(int i=1;i<=cntnd;i++)
    // {
    //     for(auto qwq:mp[i])
    //     {
    //         cout<<qwq.first<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=q;i++)
    {
        cin>>xxkan[i].l>>xxkan[i].r;
        xxkan[i].op=i;
        if(xxkan[i].l>xxkan[i].r) swap(xxkan[i].l,xxkan[i].r);
    }
    sort(xxkan+1,xxkan+q+1,cmp);
    xxkan[0]=(cx){0,0};
    for(int i=1;i<=q;i++)
    {
        if(xxkan[i].l!=xxkan[i-1].l) dijkstra(xxkan[i].l);
        ans[xxkan[i].op]=dis[xxkan[i].r];
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}