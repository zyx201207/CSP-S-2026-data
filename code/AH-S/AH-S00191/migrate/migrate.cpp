#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    //if(c==0||c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
            long long cnt=d/(a[2]-a[1]);
            if(d<a[2]-a[1]) cout<<0<<endl;
            long long ans=0;
            for(int i=2;i<=n-1;i++){
                if(i%cnt!=0) ans+=n-i;
            }
            cout<<ans<<endl;
        }
    //}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
