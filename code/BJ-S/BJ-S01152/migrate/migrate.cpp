#include <bits/stdc++.h>
using namespace std;
long long ans,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(a,0,sizeof(a));
        long long n,d;
        cin>>n>>d;
        if(d==1){
            cout<<0<<endl;
            continue;
        }
        long long x=2*d-1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                if(a[j]-a[i]==x){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
