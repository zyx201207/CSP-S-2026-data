#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll flag;
ll a[2000010];
ll pos[2000010];
ll ans[2000010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<n;i++){
        flag+=a[i]<=a[i+1];
    }
    if(m==1){
        printf("%lld",n);
        return 0;
    }
    if(flag==n-1){
        for(ll i=2;i<=n+1;i++){
            if(a[i]!=a[i-1]){
                printf("%lld ",i-1);
            }
        }
        return 0;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if(pos[a[j]]!=0){
                for(ll k=pos[a[j]];k<j;k++){
                    pos[a[k]]=0;
                }
            }
            pos[a[j]]=j;
        }
        for(ll j=i;j<=n;j++){
            ans[a[j]]+=pos[a[j]]!=0;
            pos[a[j]]=0;
        }
    }
    for(ll i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}
