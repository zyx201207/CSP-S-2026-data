#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge{
    int v;
    ll w;
};
const int MAXN=505,MAXM=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[MAXM];
vector<edge> to[MAXM];
ll f[MAXN][MAXN];
ll val[MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    //cerr<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<'\n';
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v,w;
            cin>>v>>w;
            to[v].push_back(edge{i,w});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(edge e1:to[i]){
            for(edge e2:to[i]){
                f[e1.v][e2.v]=min(f[e1.v][e2.v],e1.w+e2.w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    memset(val,0x3f,sizeof(val));
    while(q--){
        int s,t;
        cin>>s>>t;
        ll ans=inf;
        for(edge e1:to[s]){
            for(edge e2:to[t]){
                ans=min(ans,e1.w+e2.w+f[e1.v][e2.v]);
            }
        }
        cout<<ans+w[s]+w[t]<<'\n';
    }
    return 0;
}
