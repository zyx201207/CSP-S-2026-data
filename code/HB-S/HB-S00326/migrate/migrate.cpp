#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,ans=0,a[2000005],sum,d,n;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int gc=a[2]-a[1];
        int b=d/gc;
        for(int i=1;i<b;i++){
            if(n-1-i<=0)break;
            ans+=n-1-i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
