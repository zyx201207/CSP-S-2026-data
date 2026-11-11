#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005],b[500005];
ll ans = 1,sum,cnt,l = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i ++){
		b[i] = b[i-1] + a[i];
	}
	for(int i = 2;i <= n;i ++){
		while(a[i]*(i-l)-(b[i-1]-b[l-1]) > m && l < i){
			l ++;
		}
		if(a[i]*(i-l)-(b[i-1]-b[l-1]) <= m){
			ans = max(ans,i-l+1);
		}
	}
	printf("%lld",ans);
	return 0;
}

