#include <bits/stdc++.h>//我错了你其实不是图论专题我眼睛瘸了呜呜但是我的脚崴了可能真要瘸了好痛呜呜………
using namespace std;//注意空间不要大也不要小！！！
const int _ = 2000010;//感觉 T3 像人均题啊但是我根本不会做呜呜………怎么办………脚踝+半个脚掌好痛………
int c, t, n, nel[_]/*手性状物*/, len[_]/*以 i 为起点有几个最短路个数为 1 的串*/, lft[_], tot, rgh[_], nw[_], ca[_], cb[_];
long long d, a[_];
bool v[_];
void zhao(int x){
	if(v[x]){
		return ;
	}
	v[x] = 1;
	if(! cb[x]){
//		len[lft[i]] = 1;
		return ;
	}
	zhao(rgh[x]);
	len[x] = len[rgh[x]] + cb[x];
	return ;
}
void find(int x){//cout<<x<<'\n';
	if(v[x]){
		return ;
	}
	v[x] = 1;
	if(! ca[x]){
		return ;
	}
	find(lft[x]);
	nel[x] = nel[lft[x]] + ca[x];
	return ;
}
struct hhh{
	long long len, ci;
	hhh operator +(const hhh & x)const{
		if(len ^ x. len){
			return {len + x. len, 1};
		}
		else{
			return {len, ci + x. ci};
		}
	}
}dp[333][333];
//int g[333][333];
inline void solve(){
	long long ans = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			dp[i][j] = {1000000000, - 1000000000};
		}
	}
	for(int i = 1; i <= n; i ++){
		dp[i][i] = {0, 1};
		for(int j = i + 1; j <= n; j ++){
			if(a[j] - a[i] > d){
				dp[i][j] = {1000000000, - 1000000000};
//				break;
			}
			else{
				dp[i][j] = {1, 1};
			}
//			cout<<dp[i][j]. len<<' ';
		}//cout<<'\n';
	}
	
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = i; j <= n; j ++){
				if(k > i && k < j){
					if(dp[i][j]. len > dp[i][k]. len + dp[k][j]. len){
						dp[i][j] = {dp[i][k]. len + dp[k][j]. len, 1};
					}
					else if(dp[i][j]. len == dp[i][k]. len + dp[k][j]. len){
						dp[i][j]. ci ++;
					}
				}
			}
		}
	}
//	for(int k = 1; k <= n; k ++){
//		for(int i = 1; i <= n; i ++){
//			for(int j = i; j <= n; j ++){
//				if(k > i && k < j){
//					if(dp[i][j]. len > dp[i][k]. len + dp[k][j]. len){
//						dp[i][j] = {dp[i][k]. len + dp[k][j]. len, 1};
//					}
//					else if(dp[i][j]. len == dp[i][k]. len + dp[k][j]. len){
//						dp[i][j]. ci ++;
//					}
//				}
//			}
//		}
//	}
//	for(int i = 1; i <= n; i ++){
//		for(int j = 1; j <= n; j ++){
//			cout << dp[i][j]. len << ' ';
//		}cout<<'\n';
//	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(dp[i][j]. len < (j - i + 1) && dp[i][j]. ci == 2){
				ans ++;
			}
		}
	}
	cout << ans << '\n';
	return ;
}
int main(){//但是倒闭了！！！
	freopen("migrate.in", "r", stdin);
//	freopen("0.out", "w", stdout);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(0), cin. tie(0), cout. tie(0);
cin >> c >> t;
while(t --){
//	cout<<t<<'\n';
	long long ans = 0;
	cin >> n >> d;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(n <= 300){
		solve();
		continue;
	}
	int R = 0;
	for(int i = 1; i <= n; i ++){
		len[i] = nel[i] = rgh[i] = 0;
		lft[i] = 2e9;
		ca[i] = cb[i] = v[i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		while(R < n && a[R + 1] - a[i] <= d){
			R ++;
			lft[R] = i;
		}
		rgh[i] = R, lft[R] = min(lft[R], i);
	}
	for(int i = 1; i <= n; i ++){
		if(rgh[i] ^ i)
		ca[rgh[i]] ++;
	}
	for(int i = 1; i <= n; i ++){
		if(ca[i] && ! v[i]){
			find(i);
		}
	}
	for(int i = 1; i <= n; i ++){
		v[i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		if(lft[i] ^ i)
		cb[lft[i]] ++;
	}
	for(int i = 1; i <= n; i ++){
		if(cb[i] && ! v[i]){
			zhao(i);
		}
	}
	for(int i = 2; i <= n; i ++){
		if(ca[i] && cb[i - 1] && lft[i] != i - 1 && rgh[i - 1] != i && lft[i] != i && rgh[i - 1] != i - 1){
			ans += ca[i] * cb[i - 1];
		}
	}
	cout << ans << '\n';
}
	return 0;
}
/*
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
