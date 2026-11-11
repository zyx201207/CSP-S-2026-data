#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[400000],sum1[400000],a[4000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(m==n){
		ll ok=a[1];
		for(ll i=1;i<=n;i++){
			ok&=a[i];
		}
		cout<<ok;
		return 0;
	}if(m==1){
		ll maxn=-1;
		for(ll i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}if(m==2){
		ll maxn=-1;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				ll p=a[i]&a[j];
				maxn=max(maxn,p);
			}
		}
		cout<<maxn;
		return 0;
	}if(m==n-1){
		sum[1]=a[1];
		for(ll i=2;i<=n;i++){
			sum[i]=sum[i-1]&a[i];
		}
		sum1[n]=a[n];
		for(ll i=n-1;i>=1;i--){
			sum1[i]=sum1[i+1]&a[i];
		}
		ll maxn=max(sum1[2],sum[n-1]);
		for(ll i=2;i<n;i++){
			ll y=sum[i-1]&sum1[i+1];
			maxn=max(maxn,y);
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
