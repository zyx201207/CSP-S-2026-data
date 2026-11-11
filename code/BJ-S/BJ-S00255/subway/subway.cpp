#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=505,MAXM=5e5+5,MAXD=25,MAXK=20;
ll c,n,m,d,q1,dist[MAXN],t[MAXM];
vector<pair<ll,ll> >v[MAXM];
vector<pair<ll,ll> >adj[MAXN];
int main(){
//    freopen("subway.in","r",stdin);
//    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q1;
    for(ll i=1;i<=m;i++) cin>>t[i];
    for(ll i=1;i<=n;i++){
        ll k;
        cin>>k;
        map<ll,ll>mp;
        while(k--){
            ll a,b;
            cin>>a>>b;
            for(ll j=0;j<v[a].size();j++){
                if(!mp.count(v[a][j].first)){
                    mp[v[a][j].first]=b+v[a][j].second;
                }
                else{
                    mp[v[a][j].first]=min(mp[v[a][j].first],b+v[a][j].second);
                }
            }
            v[a].push_back({i,b});
        }
        for(auto j:mp){
            adj[i].push_back(j);
            adj[j.first].push_back({i,j.second});
        }
    }
    while(q1--){
        ll x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:v[x]){
            priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
            for(ll i=1;i<=n;i++){
                dist[i]=0x3f3f3f3f3f3f3f3f;
            }
            q.push({0ll,i.first});
            dist[i.first]=0;
            while(!q.empty()){
                ll u=q.top().second,d=q.top().first;
                for(auto i:adj[u]){
                    if(dist[i.first]==0x3f3f3f3f3f3f3f3f){
                        dist[i.first]=d+i.second;
                        q.push({dist[i.first],i.first});
                    }
                }
            }
            for(auto j:v[x]){
                ans=min(ans,dist[j.first]);
            }

        }
        cout<<ans+t[x]+t[y]<<'\n';
    }
}
