#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const ll N=5e3+10;
ll g[N][N];
ll c,n,m,d,q,cnt=0;
void floyd(){
    for(ll k=1;k<=cnt;k++){
        for(ll i=1;i<=cnt;i++){
            for(ll j=1;j<=cnt;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
void solve(){
    memset(g,0x3f,sizeof(g));
    cin>>c>>n>>m>>d>>q;
    ll M=m;
    ll i=1;
    while(M--){
        ll w;
        cin>>w;
        g[i][i+1]=w;
        g[i+1][i]=w;
        cnt+=2;
        i+=2;
    }
    ll last=-10086;
    ll j=1;
    for(ll i=1;i<=n;i++){
        last=-10086;
        ll t;
        cin>>t;
        while(t--){
            ll u,w;
            cin>>u>>w;
            cnt++;
            g[u*2][m*2+j]=w;
            g[m*2+j][u*2]=w;
            if(last!=-10086){
                g[m*2+j][last]=0;
                g[last][m*2+j]=0;
            }
            last=m*2+j;
            j++;
        }
    }
    for(ll i=1;i<=cnt;i++) g[i][i]=0;
    floyd();
    while(q--){
        ll st,en;
        cin>>st>>en;
        cout<<g[st*2-1][en*2-1]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
