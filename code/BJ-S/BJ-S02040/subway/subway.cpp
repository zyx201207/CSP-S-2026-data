#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll v,w;
};
vector<node> a[40505];
bool vis[40505];
ll c,n,m,dd,qq;
ll d[40505];
ll ff[40505];
ll k,l,h,x,y;
priority_queue<node>q;
bool operator<(const node &a,const node &b){
    return a.w>b.w;
}
void dijkstra(ll s){
    for(ll i=1;i<=m+n;i++) d[i]=1e18,vis[i]=0;
    d[s]=0;
    q.push({s,0});
    while(!q.empty()){
        node now=q.top();
        q.pop();
        ll t=now.v;
        if(vis[t]) continue;
        vis[t]=1;
        for(auto i:a[t]){
            ll v=i.v,w=i.w;
            if(d[v]>d[t]+w){
                d[v]=d[t]+w;
                q.push({v,d[v]});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>dd>>qq;
    for(ll i=1;i<=m;i++) cin>>ff[i];
    for(ll i=1;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>l>>h;
            a[m+i].push_back({l,h});
            a[l].push_back({m+i,h});
        }
    }
    while(qq--){
        cin>>x>>y;
        dijkstra(x);
        cout<<d[y]+ff[y]+ff[x]<<'\n';
    }
    return 0;
}
