#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=505;
struct node{int a,v;};
vector<node> k[N];
int a[N],f[M][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c,m,n,d,q;cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        int t;cin>>t;
        for(int j=1;j<=t;j++){
            int a,v;cin>>a>>v;
            k[a].push_back({i,v});
        }
    }memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++)f[i][i]=0;
    for(int i=1;i<=n;i++){
        for(auto x:k[i]){
            for(auto y:k[i]){
                if(x.a==y.a)continue;
                f[y.a][x.a]=f[x.a][y.a]=min(f[x.a][y.a],x.v+y.v);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            if(k==i)continue;
            for(int j=1;j<=m;j++){
                if(k==j || i==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x1,y1,ans=1e18;cin>>x1>>y1;
        for(auto x:k[x1]){
            for(auto y:k[y1]){
                ans=min(ans,x.v+y.v+f[x.a][y.a]);
            }
        }cout<<ans+a[x1]+a[y1]<<"\n";
    }
    return 0;
}
