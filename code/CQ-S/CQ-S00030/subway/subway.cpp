#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF=(ll)4e18;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    if(fscanf(fi,"%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q)!=5){ fclose(fi); fclose(fo); return 0; }
    vector<ll> w(m+1);
    for(ll v=1;v<=m;v++) fscanf(fi,"%lld",&w[v]);
    // lines: lists of (station, t)
    vector<vector<pair<ll,ll>>> line(n+1);
    // atStation[v] = list of (line, t)
    vector<vector<pair<ll,ll>>> atSt(m+1);
    for(ll i=1;i<=n;i++){
        ll k; fscanf(fi,"%lld",&k);
        for(ll j=0;j<k;j++){ ll a,t; fscanf(fi,"%lld %lld",&a,&t); line[i].push_back({a,t}); atSt[a].push_back({i,t}); }
    }
    // W[i][j] min transfer cost
    vector<vector<ll>> W(n+1, vector<ll>(n+1, INF));
    for(ll i=1;i<=n;i++) W[i][i]=0;
    for(ll v=1;v<=m;v++){
        auto &L=atSt[v];
        for(ll x=0;x<(ll)L.size();x++)
            for(ll y=x+1;y<(ll)L.size();y++){
                ll i=L[x].first, ti=L[x].second;
                ll j=L[y].first, tj=L[y].second;
                ll val=ti+tj;
                if(val<W[i][j]) W[i][j]=val;
                if(val<W[j][i]) W[j][i]=val;
            }
    }
    for(ll k=1;k<=n;k++){
        vector<ll> &Wk=W[k];
        for(ll i=1;i<=n;i++){
            if(W[i][k]>=INF) continue;
            ll wik=W[i][k];
            vector<ll> &Wi=W[i];
            for(ll j=1;j<=n;j++){
                if(Wk[j]>=INF) continue;
                ll v=wik+Wk[j];
                if(v<Wi[j]) Wi[j]=v;
            }
        }
    }
    for(ll r=0;r<q;r++){
        ll x,y; fscanf(fi,"%lld %lld",&x,&y);
        ll best=INF;
        for(auto &p1: atSt[x]){
            ll i=p1.first, ti=p1.second;
            for(auto &p2: atSt[y]){
                ll j=p2.first, tj=p2.second;
                if(W[i][j]>=INF) continue;
                ll val=ti+W[i][j]+tj;
                if(val<best) best=val;
            }
        }
        if(best>=INF) best=0; // should not happen (connected)
        fprintf(fo,"%lld\n", w[x]+w[y]+best);
    }
    fclose(fi); fclose(fo);
    return 0;
}

