#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+2;
long long c,t;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        long long n,d,cnt=0;
        scanf("%lld%lld",&n,&d);
        for(int i = 1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                if(a[j]-a[i]>d and (a[j]-a[i])%d==d-1){
                    cnt++;
                }
            }
        }
        printf("%lld\n",cnt);
    }
}
