#include<bits/stdc++.h>
using namespace std;
long long c,t,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int num=2*d;
        int ans=n-num+1;
        cout<<ans<<endl;

    }
    return 0;
}
