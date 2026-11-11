#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 500005;
vector<pair<ll,ll>>g[N];
ll step[N];

ll dijkstra(ll s,ll e){
    memset(step,0x3f,sizeof(step));
    priority_queue<pair<ll,ll>>pq;
    pq.push({s,0});step[s]=0;

    while(!pq.empty()){
        pair<ll,ll>frt=pq.top();pq.pop();
        if(frt.second>step[frt.first]) continue;
        for(auto to:g[frt.first]){
            ll v=to.first,c=to.second;
            if(step[frt.first]+c<step[v]){
                step[v]=step[frt.first]+c;
                pq.push({v,step[v]});
            }
        }
    }
    return step[e];
}


int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<ll>t(m+1);
    for(ll i=1;i<=m;i++) cin>>t[i];
    for(ll i=1;i<=n;i++){//subway
        ll k;cin>>k;
        vector<ll>s(k+1),t2(m+1);
        for(ll j=1;j<=k;j++){//site
            cin>>s[j]>>t2[s[j]];
        }

        for(ll j=1;j<k;j++){
            for(ll l=j+1;l<=k;l++){
                ll u=s[j],v=s[l];
                ll cost_u=t2[u],cost_v=t2[v];
                g[u].push_back({v,cost_u+cost_v});
                g[v].push_back({u,cost_u+cost_v});
            }
        }
    }

    while(q--){
        ll s,e;cin>>s>>e;
        cout<<dijkstra(s,e)+t[s]+t[e]<<endl;
    }
    return 0;
}
