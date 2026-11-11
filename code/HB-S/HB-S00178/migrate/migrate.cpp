#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
int b[2000005];
int cnt;
int sum;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(x[j]-x[i]<d) continue;
                cnt=x[j]-x[i];
                sum=cnt%d;
                if(sum==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
