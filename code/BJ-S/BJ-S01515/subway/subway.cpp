#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
int w[N];
int t[505][N];
int a[N];
int f[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f3f3f3f,sizeof f);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a1,t1;cin>>a1>>t1;
            t[i][a1]=t1;
            for(int i1=1;i1<=k;i1++){
                for(int j1=1;j1<=k;j1++){
                    if(i1!=j1&&t[i][i1]&&t[i][j1]){
                        f[i1][j1]=min(f[i1][j1],t[i][i1]+t[i][j1]);
                        f[j1][i1]=min(f[j1][i1],t[i][i1]+t[i][j1]);
                    }
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
