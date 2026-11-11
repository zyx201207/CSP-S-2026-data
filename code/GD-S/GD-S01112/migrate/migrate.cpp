#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 2e6+5;
i64 dp[N], x[N], f[N];
/* 
dp[i] 为到第i座岛屿最少需要经过多少条路
f[i] 为到第i座岛屿最短路径有几条
dp[i] = min(dp[j]+1) (x[i] - x[j] <= d); 
*/
void solve(){
	int n;
	i64 d;
	cin >> n >> d;
	int sum = 0;
	for(int i = 1;i <= n;i++) cin >> x[i];
	for(int i = 1;i <= n;i++){
		for(int j = i-1;j <= n;j++) dp[j] = 0, f[j] = 0;
		dp[i] = 0;
		f[i] = 1;
		deque<int> q;
		q.push_back(i);
		map<i64,int> tot;
		tot[0] = 1;
		int l = i;
		for(int j = i + 1;j <= n;j++){
			while(x[j] - x[l] > d){
				tot[dp[l]] -= f[l];
				l++;
			}
			while(!q.empty() && x[j]-x[q.front()] > d) q.pop_front();
			if(!q.empty()){
				dp[j] = dp[q.front()]+1;
				tot[dp[j]] += tot[dp[q.front()]];
				f[j] = tot[dp[q.front()]];
				if(tot[dp[q.front()]] == 2) sum++;
			} else{
				dp[j] = LLONG_MAX;
				f[j] = 0;
				continue;
			}
			while(!q.empty() && dp[j] <= dp[q.back()]) q.pop_back();
			q.push_back(j);
		}
	} 
	cout << sum << "\n";
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int c, t;
	cin >> c >> t;
	while(t--) solve();
}
