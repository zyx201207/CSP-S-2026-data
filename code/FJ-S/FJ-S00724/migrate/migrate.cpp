#include <bits/stdc++.h>
using namespace std ;
const int N = 2e6 + 5 ;
typedef long long ll ;
int c, t, n ; ll d ;
ll x[N] ; int dp[N], cnt[N] ;
deque<int> dq ;
ll planA(){
	ll ans = 0 ;
	for(int i = 1; i <= n; i++){
		for(int i = 0; i <= n; i++)
			cnt[i] = 0, dp[i] = -1 ;
		while(!dq.empty()) dq.pop_back();
		dp[i] = 0 ; cnt[0] = 1 ;
		for(int j = i; j <= n; j++){
			while(!dq.empty() && x[j] - x[dq.front()] > d)
				cnt[dp[dq.front()]]--, dq.pop_front();
			if(!dq.empty()){
				if(dp[dq.front()] == -1) break ;
				if(cnt[dp[dq.front()]] == 2){
					ans ++ ; 
				}
				dp[j] = dp[dq.front()] + 1 ;
				cnt[dp[j]]++ ;
			}
			dq.push_back(j) ; 
		}
	}
	return ans ;
}

ll planB(){
	for(int i = 0; i <= n; i++)
		cnt[i] = 0, dp[i] = -1 ;
	while(!dq.empty()) dq.pop_back();
	dp[1] = 0 ; cnt[0] = 1 ;
	for(int i = 1; i <= n; i++){
		while(!dq.empty() && x[i] - x[dq.front()] > d)
			cnt[dp[dq.front()]]--, dq.pop_front();
		if(!dq.empty()){
			if(dp[dq.front()] == -1) break ;
			if(cnt[dp[dq.front()]] == 2) return n - i + 1 ;
			dp[i] = dp[dq.front()] + 1 ;
			cnt[dp[i]]++ ; 
		}
		dq.push_back(i) ;
	}
	return 0 ;
}
int main(){
	freopen("migrate.in", "r", stdin) ;
	freopen("migrate.out", "w", stdout) ;
	scanf("%d%d", &c, &t) ;
	while(t--){
		scanf("%d%lld", &n, &d) ;
		for(int i = 1; i <= n; i++) scanf("%lld", x + i) ;
		if(c >= 11 && c <= 12) printf("%lld\n", planB()) ;
		else printf("%lld\n", planA()) ;
	}
	return 0 ;
}
