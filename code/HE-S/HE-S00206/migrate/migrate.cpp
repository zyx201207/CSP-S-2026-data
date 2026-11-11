#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000;
ll c,t,n,d,a[maxn],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld",&c);
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld",&n);
		scanf("%lld",&d);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(ll i=1;i+3<=n;i++){
			ll j=i+3;
			if(a[j]-a[i+1]<=d&&a[i+1]-a[i]<=d&&a[j-1]-a[i]<=d&&a[j]-a[j-1]<=d&&a[j]-a[i]>d){
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
