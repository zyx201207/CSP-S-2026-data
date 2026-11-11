/**********************
 ~AUTHOR BY "ILWF^_^" 
 ~author by "ILWF^_^" 
**********************/
#include<bits/stdc++.h>
#define LM LLONG_MAX
#define ILW return
#define F 0
using namespace std;
using ll = long long;
const ll N = 2000005 , M = 5005;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
ll a[N] , dp[M][M] , cnt[M][M] , num[M];
ll n , d;
void solve1(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	deque<ll> q;
	for(int i = 1;i <= n;i++){
		q.clear();
		queue<ll> qq;
		dp[i][i] = 0 , cnt[i][i] = 1;
		for(int j = i + 1;j <= n;j++) dp[i][j] = INF , cnt[i][j] = 0;
		for(int j = 0;j <= n;j++) num[j] = 0;
		num[0] = 1;
		q.push_back(i);
		for(int j = i + 1;j <= n;j++){
			while(!q.empty() && a[j] - a[q.front()] > d) q.pop_front();
			while(!qq.empty() && a[j] - a[qq.front()] > d) num[dp[i][qq.front()]] -= cnt[i][qq.front()] , qq.pop();
			if(!q.empty()) dp[i][j] = dp[i][q.front()] + 1 , cnt[i][j] = num[dp[i][q.front()]];
			while(!q.empty() && dp[i][q.back()] > dp[i][j]) q.pop_back();
			if(dp[i][j] != INF) q.push_back(j) , num[dp[i][j]] += cnt[i][j] , qq.push(j);
		}
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++) ans += (cnt[i][j] == 2);
	}
	cout << ans << '\n';
}
ll dp2[N] , cnt2[N];
void solve2(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	deque<ll> q;
	queue<ll> qq;
	dp2[1] = 0 , cnt2[1] = 1;
	for(int j = 2;j <= n;j++) dp2[j] = INF , cnt2[j] = 0;
	for(int i = 0;i <= n;i++) num[i] = 0;
	num[0] = 1;
	q.push_back(1);
	for(int j = 2;j <= n;j++){
		while(!q.empty() && a[j] - a[q.front()] > d) q.pop_front();
		while(!qq.empty() && a[j] - a[qq.front()] > d) num[dp2[qq.front()]] -= cnt2[qq.front()] , qq.pop();
		if(!q.empty()) dp2[j] = dp2[q.front()] + 1 , cnt2[j] = num[dp2[q.front()]];
		while(!q.empty() && dp2[q.back()] > dp2[j]) q.pop_back();
		if(dp2[j] != INF) q.push_back(j) , num[dp2[j]] += cnt2[j] , qq.push(j);
	}
	ll ans = 0;
	for(int i = 1;i <= n;i++) if(dp2[i] == 2) ans += (n - i + 1);
	cout << ans << '\n';
}
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c , t = 1;
	cin >> c >> t;
	if(c <= 10){
		while(t--) solve1();
	}else if(11 <= c && c <= 12){
		while(t--) solve2();
	}else{
		while(t--) solve1();
	}
	ILW F; 
}
