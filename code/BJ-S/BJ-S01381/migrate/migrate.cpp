#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int c,t;
int x[N];
int dis[N][N];
int f[N][N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i = 1;i <= n;i++){
            cin>>x[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = abs(x[i]-x[j]);
                f[i][j] = min(dis[i][j],min(dis[i-1][j],dis[i][j-1]));
            }
        }
        cout<<f[1][n]<<endl;
    }
    return 0;
}
