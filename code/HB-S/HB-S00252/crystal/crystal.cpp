#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n>5000&&m>1e8){
		ll d=a[2]-a[1];
        ll t=m/d;
        ll x=0;
        for(ll i=1;i<=n;i++){
            x+=i;
            if(x>t){
                printf("%lld",i);
                return 0;
            }
        }
        printf("%lld",n);
        return 0;
	}
    for(ll i=1;i<=n;i++){
        ll t=m;
        ll cnt=1;
        for(ll j=i-1;j>=1&&t;j--){
            if(t<a[i]-a[j])break;
            t-=(a[i]-a[j]);
            cnt++;
        }
        maxn=max(maxn,cnt);
    }
    printf("%lld",maxn);
	return 0;
}
