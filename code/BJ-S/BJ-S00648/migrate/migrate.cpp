#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,z[2000005]={};
long long f[5005][5005]={},ci[5005][5005]={};
long long ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int o = 1;o <= t;o++){
        cin>>n>>d;
        for(int i = 1;i <= n;i++){
            cin>>z[i];
        }
        for(int i = 1;i <= n-1;i++){
            for(int j = 1;i+j<=n;j++){
                if(z[i+j]-z[j]<=d) f[j][i+j] = 1;
                else{
                    f[j][i+j] = 5005;
                    for(int k = j+1;k <= i+j-1;k++){
                        if(f[j][k]+f[k][i+j]==f[j][i+j]) ci[j][i+j]++;
                        if(f[j][k]+f[k][i+j]<f[j][i+j]){
                            f[j][i+j] = f[j][k]+f[k][i+j];
                            ci[j][i+j] = 1;
                        }
                    }
                    if(ci[j][i+j]==2&&f[j][i+j]<=5000) ans++;
                }

            }
        }
        cout<<ans<<endl;
        memset(f,0,sizeof(f));
        memset(ci,0,sizeof(ci));
        ans = 0;
    }
}
