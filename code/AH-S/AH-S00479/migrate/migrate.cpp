#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define ll long long
ll n,a[N],c,t,d;
ll f[N][N],g[N][N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ll ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=1e18,g[i][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    f[i][j]=0;
                    continue;
                }
                if(abs(a[i]-a[j])<=d){
                    f[i][j]=1;
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(f[i][k]+f[k][j]<=d){
                        g[i][j]=1;
                        f[i][j]=1;
                        continue;
                    }
                    if(f[i][k]+f[k][j]<f[i][j]){
                        g[i][j]=1;
                        f[i][j]=f[i][k]+f[k][j];
                        continue;
                    }
                    if(f[i][k]+f[k][j]==f[i][j]){
                        g[i][j]++;
                        f[i][j]=f[i][k]+f[k][j];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j&&f[i][j]>0){
                    if(g[i][j]==2)
                        ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
