#include<bits/stdc++.h>
using namespace std;
long long n,c,t,a[15],d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=2){
        while(t--){
            cin>>n>>d;
            for(int i=0;i<15;i++) a[i]=0;
            for(int i=1;i<=n;i++) cin>>a[i];
            if(n<=3){
                cout<<0<<'\n';
                continue;
            }
            int ans=0;
            for(int i=1;i<=n-3;i++){
                for(int j=i+3;j<=n;j++){
                    if(a[i+1]-a[i]<=d && a[j]-a[i]<=d && a[i+2]-a[i]<=d && a[j]-a[i+2]<=d) ans++;
                }
            }
            for(int i=1;i<=n-4;i++){
                int zhi=0;
                for(int j=i+4;j<=n;j++){
                    if(a[i+2]-a[i]<=d && a[j]-a[i+2]<=d){
                        zhi=1;
                        break;
                    }
                    
                }
                if(zhi) break;
            }
            cout<<ans<<'\n';
        }
    }
}