#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int f[5005];
int all[5005];
int x[2000005];
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) f[j]=10000,all[j]=0;
            f[i]=0,all[i]=1;
            for(int j=i;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(abs(x[j]-x[k])>d) break;
                    f[j]=min(f[j],f[k]+1);
                }
                for(int k=j-1;k>=i;k--){
                    if(abs(x[j]-x[k])>d) break;
                    if(f[k]==f[j]-1) all[j]+=all[k];
                }
                if(all[j]==2) ans++;
            }
        }
        cout<<ans<<"\n";
        //cout<<"\n";
    }
    return 0;
}