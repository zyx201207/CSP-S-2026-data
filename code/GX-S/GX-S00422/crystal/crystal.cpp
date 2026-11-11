#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=1;
ll a[500010];
ll b[500010],h=1,t,sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[++t]=i;
		sum+=(i-1)*(a[i]-a[i-1]);
		while(h<=t&&sum>m){
			sum-=a[i]-a[b[h]];
			h++;
		}
		ans=max(ans,t-h+1);
	}
	printf("%lld",ans);
	return 0;
}
