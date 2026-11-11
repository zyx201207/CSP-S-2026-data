#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll C,n,m,d,Q,w[N],k[505],a,t,g[505][505],f[505][505],s,T,p[505][505],q[505][505];
struct node{
    ll v,w;
};
vector<node> u[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            u[a].push_back({i,t});
        }
    }
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++){
        for(auto x:u[i]){
            for(auto y:u[i]){
                if(x.v==y.v) continue;
                g[x.v][y.v]=x.w+y.w;
                g[y.v][x.v]=g[x.v][y.v];
                p[x.v][y.v]=q[x.v][y.v]=p[y.v][x.v]=q[y.v][x.v]=i;

            }
        }
    }
    for(int i=1;i<=n;i++){
        g[i][i]=0;
        p[i][i]=q[i][i]=0;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(g[i][j]>g[i][k]+g[k][j]){
                    g[i][j]=g[i][k]+g[k][j];
                    p[i][j]=p[i][k];
                    q[i][j]=q[k][j];
                }
            }
    while(Q--){
        cin>>s>>T;
        ll ans=0x3f,pp,qq;
        for(auto x:u[s]){
            for(auto y:u[T]){
                if(g[x.v][y.v]<ans){
                    ans=g[x.v][y.v];
                    pp=x.v;
                    qq=y.v;
                }
            }
        }
        ll l=p[pp][qq],r=q[pp][qq];
        if(s==l){
            for(auto x:u[s])
                if(x.v==pp) ans-=x.w;
        }
        else {
            for(auto x:u[s])
                if(x.v==pp) {
                    ans+=x.w;
                        }
        }
        if(T==r){
            for(auto x:u[T])
                if(x.v==qq) ans-=x.w;
        }
        else {
            for(auto x:u[T])
                if(x.v==qq) ans+=x.w;
        }
        cout<<ans+w[s]+w[T]<<"\n";
    }
    return 0;
}
/*
*/
