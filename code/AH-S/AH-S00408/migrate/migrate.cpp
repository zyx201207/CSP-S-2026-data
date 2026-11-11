#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,t,n,d,a[20000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        LL cnt=0;
        for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                if(j-i-1==2) cnt++;
            }
        }
        printf("%lld",cnt);
    }
    return 0;
}
