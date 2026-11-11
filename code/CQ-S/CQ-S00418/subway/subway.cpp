#include<bits/stdc++.h>
#define ll long long
#define pii pair<int ,int >
#define pll pair<long long, long long >

using namespace std;
const ll N=5e5+5,M=505,W=1e9,mod=998244353,INF=1e18;
ll n,m,d,q,arr[N];
ll dis[M][M],diss[N+M];

vector<pll >vec[M];
vector<pll >ve[N+M];
void dijkstra(ll st){
    priority_queue<pll ,vector<pll>,greater<pll> >pq;
    pq.push({0,st});
    memset(diss,0x3f,sizeof diss);
    diss[st]=0;
    while(pq.empty()==0){
        ll x=pq.top().second,w=pq.top().first;
        //cout<<x<<' '<<w<<'\n';
        pq.pop();
        if(diss[x]!=w)continue;
        for(auto i:ve[x]){
            if(diss[i.first]>w+i.second){
                diss[i.first]=w+i.second;
                pq.push({w+i.second,i.first});
            }
        }
    }
    for(int i=1;i<=n;++i){
        dis[st-N][i]=diss[N+i];
    }
}
void sol(){
    cin>>n>>m>>d>>q;
    for(ll i=1;i<=m;++i){
        cin>>arr[i];
    }
    for(ll i=1;i<=n;++i){
        ll x;
        cin>>x;
        for(ll j=1;j<=x;++j){
            ll a,b;
            cin>>a>>b;
            vec[i].push_back({a,b});
            ve[a].push_back({N+i,b});
        }
    }
    
    memset(dis,0x3f,sizeof dis);
    for(ll i=1;i<=n;++i){
        dis[i][i]=0;
        for(pll j:vec[i]){
            for(pll k:ve[j.first]){
                ve[N+i].push_back({k.first,j.second+k.second});
                ve[k.first].push_back({N+i,j.second+k.second});
                //cerr<<k.first<<'\n';
            }
            
        }
        dijkstra({N+i});
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll minn=INF;
        for(pii i:ve[a]){
            for(pii j:ve[b]){
                minn=min(minn,min(dis[i.first-N][j.first-N],dis[j.first-N][i.first-N])+i.second+j.second);
            }
        }
        
        cout<<minn+arr[a]+arr[b]<<'\n';

    }

}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t=1;
    int c=0;
    //cin>>t;
    cin>>c;
    while(t--){
        sol();
    } 
    //cerr<<clock();
    return 0;
}
/*
author:_aa_

*/
