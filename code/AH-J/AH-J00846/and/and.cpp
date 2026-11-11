#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],maxn=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",a+i);
        maxn=max(a[i],maxn);
    }
    if(m==1) printf("%lld",maxn);
    else if(m==2){
        ll maxx=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        printf("%lld",maxx);
    }
    else if(m==n){
        ll x=a[1];
        for(ll i=2;i<=n;i++){
            x=x&a[i];
        }
        printf("%lld",x);
    }
    else if(m==n-1){
        ll x,maxx=0;
        for(ll i=1;i<=n;i++){
            if(i==1) x=a[2];
            else x=a[1];
            for(ll j=1;j<=n;j++){
                if(i==j) continue;
                x=x&a[j];
            }
            maxx=max(maxx,x);
        }
        printf("%lld",maxx);
    }
    else{
        sort(a,a+1+n);
        ll x=a[n-m+1];
        for(ll i=n-m+2;i<=n;i++){
            x=x&a[i];
        }
        printf("%lld",x);
    }
    return 0;
}
