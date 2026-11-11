#include<bits/stdc++.h>
using namespace std;
inlong long c,t,n,m,a[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        long long ans=0;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            ans+=a[i];
        }
        if(ans>=0){
            ans/=n+m;

        }else{
            ans=0-ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}
