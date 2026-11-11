#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,x[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        int cnt=0,ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d) continue;
                for(int k=i;k<=j;k++){
                    if(x[k]-x[i]<=d && x[j]-x[k]<=d) cnt++;
                }
                if(cnt==2) ans++;
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
