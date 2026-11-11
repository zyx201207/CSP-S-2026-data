#include<bits/stdc++.h>
using namespace std;
const int N=500000+5;
typedef long long ll;
ll n,m,d,c,q,stop[502][502],w[N],t[N][501];
vector<int>g[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(stop,0x3f,sizeof stop);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        ll k;
        cin>>k;
        for(int j=1;j<=k;++j){
            ll x;
            cin>>x>>t[x][i];
            g[x].push_back(i);
        }
    }
    for(int i=1;i<=m;++i){
        ll b[21],l=1,r=0;
        for(auto d : g[i]){
            b[++r]=d;
            if(r>1){
                ll op=r-1;
                while(op>=1){
                    ll x=b[r],y=b[op];
                    stop[x][y]=min(t[i][x]+t[i][y],stop[x][y]);
                    stop[y][x]=stop[x][y];
                    op--;
                }
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                stop[i][j]=min(stop[i][j],stop[i][k]+stop[k][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        ll x,y;
        cin>>x>>y;
        ll ans=0x3f3f3f;
        for(auto d:g[x]){
            for(auto v:g[y]){
                ll minn=w[x]+t[x][d]+stop[d][v]+t[y][v]+w[y];
                if(d==v)minn=w[x]+t[x][d]+t[y][v]+w[y];
                ans=min(ans,minn);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
