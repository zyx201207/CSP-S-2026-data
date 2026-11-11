#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],len[505];
int c,n,m,d,q;
bool v[505];
struct dot
{
    int id,w;
    bool operator < (const dot &x) const{
        return w>x.w;
    }
};
struct node
{
    int v,w;
};
vector<node> a[505];
int dijstra(int s,int e)
{
    priority_queue<dot> q;
    fill(v+1,v+n+1,0);
    fill(len+1,len+n+1,LLONG_MAX/2);
    len[s]=0;
    q.push({s,len[s]});
    while(!q.empty())
    {
        dot now=q.top();
        if(v[now.id]) continue;
        v[now.id]=1;
        for(auto i:a[now.id])
        {
            if(len[now.id]+a[now.id].w<len[a[now.id].v])
            {
                len[a[now.id].v]=len[now.id]+a[now.id].w;
                q.push({a[now.id].v,len[a[now.id].v]});
            }
        }
    }
    return len[e];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int v,w;
        cin>>v>>w;
        a[i].push_back({v,w});
        a[v].push_back({i,w});
    }
    while(q--)
    {
        int s,e;
        cin>>s>>e;
        cout<<dijstra(s,e)<<'\n';
    }
    return 0;
}
