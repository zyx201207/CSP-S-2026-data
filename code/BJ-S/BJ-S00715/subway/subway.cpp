#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int c,n,m,d,q;
int w[N];
int f[N][N];
int a[N][N];
int t[N][N];
bool vis;
int k[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,ti;cin>>x>>ti;
            a[i][x]=1;
            t[i][x]=ti;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=1000000000;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j){
                    continue;
                }
                if(a[k][i] and a[k][j]){
                    f[i][j]=min(f[i][j],t[k][i]+t[k][j]);
                    f[j][i]=f[i][j];
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j){
                    continue;
                }
                if(f[i][k]!=1000000000 and f[j][k]!=1000000000){
                    f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
                }
            }
        }
    }
    while(q--){
        int xr,yr;cin>>xr>>yr;
        int ans=f[xr][yr]+w[xr]+w[yr];
        cout<<ans<<"\n";
    }
    return 0;
}
