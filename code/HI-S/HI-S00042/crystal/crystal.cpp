#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5 * 1e5 + 5;
ll a[N],p[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		p[i] = a[i] + p[i - 1];
	ll ans = 0LL;
	ll l = 1LL,i = 1LL;
	while(i <= n && l <= n && l <= i){
		ll s = (i - l) * a[int(i)];
		ll now = p[int(i) - 1] - p[int(l) - 1];
		i += 1LL;
		if(m >= s - now){
			if(i - l > ans){
				ans = i - l;
			}
		}else{
			l += 1LL;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
