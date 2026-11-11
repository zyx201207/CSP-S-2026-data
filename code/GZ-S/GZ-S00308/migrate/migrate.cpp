//GZ-S00308 贵阳市第十七中学 徐廷蔚 
#include<bits/stdc++.h>
using namespace std;
int T;
int n;
long long d,x[2000005];
int c;
struct node{
	int la;
	long long len;
}; 
long long dp[5005][5005];
void solve() {
	cin >> n >> d;
	for(int i = 1;i <= n;i ++) {
		cin >> x[i];
	}
	long long ans = 0;
	for(int i = 1;i <= n;i ++) {
		for(int j = i + 1;j <= n;j ++) {
			map<long long,int>mp;
			long long minn = 0x3f3f3f3f3f3f3f3f;
			queue<node>q;
			q.push({i,0});
			while(q.size()) {
				node tmp = q.front();
				q.pop();
				if(tmp.la > j) continue;
				if(tmp.la == j) {
					minn = min(minn,tmp.len);
					mp[tmp.len] ++;
					continue;
				}
				for(int k = tmp.la + 1;x[k] - x[tmp.la] <= d&&k <= j;k ++) {
					q.push({k,tmp.len+1});
				}
			}
			if(mp[minn] == 2) {
				ans ++;
			//	cout << i << " " << j << "\n";
			}
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T --) solve();
	return 0;
} 
