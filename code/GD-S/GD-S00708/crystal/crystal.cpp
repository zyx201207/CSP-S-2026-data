#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=5e5+5;
ll n,m;
ll a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll l=1,sum=0,ans=0;
	for(ll i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(l<=i&&sum>m){
			sum-=a[i]-a[l++];
		}
		ans=max(ans,i-l+1ll);
	}
	printf("%lld",ans);
}
