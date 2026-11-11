#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5,INF=4e18;
ll c,T,cnt;
ll n,d;
ll x[N],dis[N],vis[N],ans[N];
vector<ll> g[N];
struct node{
    ll to,dis;
    const bool operator < (const node &tmp) const{
        return dis<tmp.dis;
    }
};
priority_queue<node> pq;
void dijkstra(ll u){
    for(ll i=1;i<=n;i++) dis[i]=INF;
    for(ll i=1;i<=n;i++) vis[i]=0;
    for(ll i=1;i<=n;i++) ans[i]=0;
    dis[u]=0;
    ans[u]=1;
    pq.push({u,0});
    while(pq.size()){
        ll uu=pq.top().to;
        pq.pop();
        if(vis[uu]) continue;
        vis[uu]=1;
        for(ll i=0;i<g[uu].size();i++){
            ll v=g[uu][i];
            if(dis[uu]+1<dis[v]){
                dis[v]=dis[uu]+1;
                ans[v]=ans[uu];
                pq.push({v,-dis[v]});
            }else if(dis[uu]+1==dis[v])
                ans[v]+=ans[uu];
        }
    }
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    for(int kkk=1;kkk<=T;kkk++){
        cnt=0;
        cin>>n>>d;
        for(ll i=1;i<=n;i++) g[i].clear();
        for(ll i=1;i<=n;i++) cin>>x[i];
        ll L=1;
        for(ll u=1;u<=n;u++){
            while(L<u&&x[u]-d>x[L]) L++;
            for(ll v=L;v<u;v++){
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        //for(ll u=1;u<=n;u++)
            //for(ll v=1;v<=n;v++)
                //if(u!=v&&abs(x[v]-x[u])<=d) g[u].push_back(v);
        for(ll u=1;u<=n;u++){
            dijkstra(u);
            for(ll v=1;v<=n;v++){
                if(ans[v]==2){
                    cnt++;
                    //cout<<"u:"<<u<<" v:"<<v<<"\n";
                }
            }
        }
        cout<<cnt/2<<"\n";
    }
    return 0;

}
//x1 x2 ... xn
//bei       nan
//|xi-xj|<=d
//
//(u,v) qia you liang tiao zuiduan lu
