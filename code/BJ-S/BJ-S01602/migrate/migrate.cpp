#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005],x;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d;cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        x=a[2]-a[1];
        d/=x;
        if(d<=2){
            cout<<0<<endl;
        }
        else {
            long long ans=0;
            for(int i=1;i<=k;i++){
                ans+=(n-i-1)/k   
            }
        cout<<ans<<endl;
        }
    }
    return 0;
}
