#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5*1e5+10;
ll n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	ll p = 1,q = 0,js = 0;
	for(int i = 2;i<=n;i++){
		js++;
		ll jg = a[i]-a[i-1];
		q+=js*jg;
		if(q>m){
			ans = max(ans,js);
			js--;
			q-=(a[i-1]-a[p]);
			p++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
