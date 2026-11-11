#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,d;
        cin>>n>>d;
        long long x[200005];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long ans=0;
        ans=n/d-1;
        cout<<ans<<"\n";
    }
    return 0;
}
