#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,ans=0;
        cin>>n>>d;
        long long x;
        for(int i=1;i<=n;i++)cin>>x;
        for(int i=1;i<=n-3;i++){
            ans+=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
