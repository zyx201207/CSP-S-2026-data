#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x = 0,h = 1;
    char ch = getchar();
    while(!(ch=='-'||('0'<=ch&&ch<='9'))) ch = getchar();
    if(ch=='-') h = -1;
    else x = ch-'0';
    ch = getchar();
    while('0'<=ch&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*h;
}
namespace G4M1{
    const ll N = 510;
    const ll D = 24;
    const ll M = 500010;
    const ll INF = 1e16;
    ll cid,n,m,d,Q;
    ll wt[M];
    vector<pair<ll,ll>> dc[M];
    ll dis[N][N];
    void main(){
        cid = read(),n = read(),m = read(),d = read(),Q = read();
        for(ll i = 1; i <= m; i++) wt[i] = read();
        for(ll i = 1; i <= n; i++){
            ll len = read();
            for(ll j = 1; j <= len; j++){
                ll x = read(),t = read();
                dc[x].push_back({i,t});
            }
        }
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++){
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
        for(ll i = 1; i <= m; i++){
            ll ds = (ll)dc[i].size();
            for(ll p1 = 0; p1 < ds; p1++) for(ll p2 = p1+1; p2 < ds; p2++){
                ll id1 = dc[i][p1].first,len1 = dc[i][p1].second;
                ll id2 = dc[i][p2].first,len2 = dc[i][p2].second;
                //printf("")
                dis[id1][id2] = min(dis[id1][id2],len1+len2);
                dis[id2][id1] = min(dis[id2][id1],len1+len2);
            }
        }
        for(ll k = 1; k <= n; k++) for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++){
            dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
        }
        while(Q--){
            ll x = read(),y = read();
            ll ans = INF;
            for(ll p1 = 0; p1 < (ll)dc[x].size(); p1++){
                for(ll p2 = 0; p2 < (ll)dc[y].size(); p2++){
                    ll id1 = dc[x][p1].first,id2 = dc[y][p2].first;
                    //printf("[%lld==%lld]\n",id1,id2);
                    ans = min(ans,dis[id1][id2]+dc[x][p1].second+dc[y][p2].second);
                }
            }
            printf("%lld\n",ans+wt[x]+wt[y]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    G4M1::main();
    return 0;
}
