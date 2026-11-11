#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n , d , a[N] , dp[N] , ans , suf[N];
void mian(){
	scanf("%lld%lld" , &n , &d);
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	ans = 0;
	for(int l = 1;l <= n;l++){
		for(int i = l;i <= n;i++) dp[i] = LONG_LONG_MAX , suf[i] = 0;
		int z = l;
		dp[l] = 0;
		suf[l] = 1;
		for(int i = l+1;i <= n;i++){
			while(a[i]-a[z] > d) suf[++z] += suf[z-1] - 1;
			dp[i] = dp[z] + 1;
			suf[z+suf[z]]++;
			if(suf[z] == 2) ans++;
		}
	}
	printf("%lld\n" , ans);
}
signed main(){
	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	int T;
	scanf("%lld" , &T);
	scanf("%lld" , &T);
	while(T--) mian();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
