#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
long long f[N][N];
int c,n,m,d,q,a[N],indx;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    cin>>c>>n>>m>>d>>q;
    indx = m;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
            f[i][j] = 0x3f3f3f3f;
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int u, dis;
            cin>>u>>dis;
            if(j == 1){
                f[u][indx+1] = f[indx+1][u] = dis;
                indx++;
            }
            else{
                f[indx][indx+1] = f[indx+1][indx] = 0 ;
                f[u][indx+1] = f[indx+1][u] = dis ;
                indx++;
            }
        }
    }
    for(int i=1;i<=indx;i++)
        for(int j=1;j<=indx;j++)
            for(int k=1;k<=indx;k++){
                f[j][k] = f[k][j] = min(f[j][k],f[j][i] + f[k][i]);
            }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<a[x]+a[y]+f[x][y]<<"\n";
    }
    return 0;
}
