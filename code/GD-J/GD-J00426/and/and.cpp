#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n,m,x,u = 1,a[N];
inline void dfs(ll i,ll sum){
	for(i;i <= n;i ++){
		if(u + 1 == m){
			x = max(x,sum & a[i]);
			return ;
		}u ++;
		dfs(i + 1,sum & a[i]);
		u --;
		dfs(i + 1,sum);
	}
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n;i ++){
		scanf("%lld",a + i);
		x = max(x,a[i]);
	}if(m == 1){
		printf("%lld",x);
		return 0;
	}if(m == 2){
		x = 0;
		for(ll i = 1;i <= n;i ++){
			for(ll j = i + 1;j <= n;j ++){
				x = max(x,a[i] & a[j]);
			}
		}printf("%lld",x);
		return 0;
	}if(m == n){
		x = a[1];
		for(ll i = 2;i <= n;i ++){
			x = x & a[i];
		}printf("%lld",x);
		return 0;
	}x = 0;
	dfs(2,a[1]);
	printf("%lld",x);
	return 0;
}
//50ртио 
