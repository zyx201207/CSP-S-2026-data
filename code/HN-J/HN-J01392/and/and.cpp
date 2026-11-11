#include <bits/stdc++.h>
using namespace std;
long long n,m;
//int dp[1000000000][1000000000];
vector<long long> a;
void init(){
	cin >> n >> m;
	for(int i = 0;i < n;++i){
		long long x;
		cin >> x;
		a.push_back(x);
	}
}
long long dfs(long long ans,long long k,long long step){
	if(step >= m)return a[k];
	long long pos = 0;
	for(int i = 0;i < n;++i){
		if(k!=i){
			//if(dp[m - step][i])pos = dp[m - step][i];
			//else {
			pos = max(dfs(ans,i,step + 1),pos);
			//	dp[m - step][i] = pos;
			//}
		}
	} 
	return ans & pos;
}
void solve(){
	long long ans = 0;
	if(m == 1){
		for(int i = 0;i < n;++i){
			ans = max(ans,a[i]);
		}
	} 
	else {
		for(int i = 0;i < n;++i){
			for(int j = i + 1;j  < n;++j){
				ans = max(ans,a[i] & a[j]);
			}
		}
	}
	cout << ans;
} 
 int main(){
 	freopen("and.in","r",stdin);
 	freopen("and.ans","w",stdout);
 	init();
 	//solve();
 	long long ans = 0;
 	for(long long i = 0;i < n;++i){
 		ans = max(ans,dfs(a[i],i,1));
	}
	cout << ans;
 	return 0;
 }
