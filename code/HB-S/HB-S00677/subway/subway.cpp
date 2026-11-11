#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=5e5+510,mod=998244353;
const ll inf=1e18;
int c,n,m,d,q;
ll w[N],k[510];
vector<pii> g[N];
ll f[510][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    fastio
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll a,t;
            cin>>a>>t;
            g[i+m].push_back({t,a});
            g[a].push_back({t,i+m});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=inf;
        }
        f[i][i]=0;
    }//2.5e4
    for(int i=m+1;i<=m+n;i++){
        for(auto j:g[i]){
            for(auto k:g[j.second]){
                if(k.second==i) continue;
                f[i-m][k.second-m]=min(f[i-m][k.second-m],j.first+k.first);
            }
        }
    }//1e7
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }//1.3e7
    while(q --){//400*1e5=4e7
        int x,y;
        cin>>x>>y;
        ll ans=inf;
        ll base=w[x]+w[y];
        ll base2=0;
        for(auto i:g[x]){//20
            for(auto j:g[y]){//20
                ans=min(ans,f[i.second-m][j.second-m]+i.first+j.first);
            }
        }
        cout<<base+ans<<"\n";
    }
    return 0;
}
/*
g++ subway.cpp -o b
./b

*/