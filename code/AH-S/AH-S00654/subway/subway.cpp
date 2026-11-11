#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ffor(i,a,b) for(ll i=(a);i<(b);++i)
#define pb push_back
struct Node{
    ll t[2]; // 到 A 厅和 B 厅的时间
    ll l[2]; // 所属的地铁线
};
ll w[500500];
Node stop[500500];
vector<pair<ll,ll>> pln;
map<pair<ll,ll>,ll> f;
// void dfs(ll srt,ll end,ll np,ll nt){
//     // if(np==end) f[{srt,end}]= ((f[{srt,end}]==0) ? nt : min(f[{srt,end}],nt));
//     // if(nt>f[{srt,end}]&&f[{srt,end}]!=0)return;
    
// }
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("subway.in","r",stdin);
    // freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    ffor(i,0,m)cin>>w[i];
    // if(1||(9<=c&&c<=11)){
        ffor(i,0,n){
            ll k;
            cin>>k;
            ffor(j,0,k){
                ll a,t;
                cin>>a>>t;
                Node zh=stop[a];
                if(zh.t[0]) zh.t[1]=t;
                else zh.t[0]=t;
                if(zh.l[0]) zh.l[1]=i;
                else zh.l[0]=i;
            }
        }
        ffor(i,0,q){
            ll x,y;
            cin>>x>>y;
            cout<<w[x-1]+w[y-1]<<'\n';
        }
        // cout<<
    // }
    return 0;
}