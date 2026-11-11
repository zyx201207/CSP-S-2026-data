#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,ln=5e5+5; // 不要用错
int cid;
int n,m,D,Q;
ll w[ln];
ll f[N][N];
vector<pair<int,int>> a[ln];
void ckmin(ll &x,const ll &y) {if(y<x) x=y;} 
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>cid>>n>>m>>D>>Q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i) {
        int k; cin>>k;
        for(int j=1;j<=k;++j) {
            int x,v; cin>>x>>v;
            a[x].emplace_back(i,v);
        }
    } 
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i) f[i][i]=0;
    for(int i=1;i<=m;++i) {
        for(int j=0;j<a[i].size();++j) {
            for(int k=j+1;k<a[i].size();++k) {
                auto [x,v1]=a[i][j];
                auto [y,v2]=a[i][k];
                ckmin(f[x][y],v1+v2);
                ckmin(f[y][x],v1+v2);
            }
        }
    }
    for(int k=1;k<=n;++k) {
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=n;++j) {
                ckmin(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(Q--) {
        int x,y; cin>>x>>y;
        ll ans=1e18;
        for(auto [j,v1]:a[x]) for(auto [k,v2]:a[y]) {
            ckmin(ans,v1+v2+f[j][k]);
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}