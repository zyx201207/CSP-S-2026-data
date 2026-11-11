#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll c,t;
ll n,d;
ll pos;
ll sum;
ll a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    if(c==11||c==12){
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(ll i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            if(d/(a[2]-a[1])<2){
                printf("0\n");
                continue;
            }
            printf("%lld\n",max(0ll,n-2*d/(a[2]-a[1])+1));
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--){
            scanf("%lld%lld",&n,&d);
            for(ll i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            for(ll i=1;i<=n;i++){
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                    pos=i;
                    break;
                }
            }
            printf("%lld\n",(pos-1)*(n-pos));
        }
        return 0;
    }
    while(t--){
        sum=0;
        scanf("%lld%lld",&n,&d);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(ll i=1,j=1,k;i<=n;i++){
            while(a[j]-a[i]<=d&&j<=n){
                j++;
            }
            j--;
            k=j;
            while(a[k]-a[j]<=d&&k<=n){
                k++;
            }
            k--;
            sum+=(j-i)*(k-j);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
