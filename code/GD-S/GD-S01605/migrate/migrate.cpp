#include<bits/stdc++.h>
using namespace std;

int n;
long long d;
int ret = 0;
vector<long long> x;
vector<int> pre,dp,ans;

void getpre() {
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (x[i] - x[j] > d) j++;
		pre[i] = j;
//		cout << x[i] << " " << x[pre[i]] << endl; 
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		dp[i] += i - pre[i];
		if (pre[i] == i) continue;
		dp[i] += pre[pre[i]];
		dp[i] += pre[pre[i]+1] - pre[pre[i]];
		if (pre[i]+1 < i) {
			ans[i] += pre[pre[i]+2] - pre[pre[i]+1];
			if (pre[pre[i]] == pre[pre[i]+1]) {
				ans[i] += dp[pre[pre[i]]];
			}
			if (pre[i] == pre[pre[i]+1]) ans[i] += ans[pre[i]];
		}
		if (pre[pre[i]] != i) ans[i] += ans[pre[pre[i]]];
		ret += ans[i];
	}
}

void resize() {
	x.clear();
	pre.clear();
	dp.clear();
	ans.clear();
	ret = 0;
	x.resize(n,0);
	pre.resize(n,0);
	dp.resize(n,0);
	ans.resize(n,0);
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while (t--) {
		scanf("%d%lld",&n,&d);
		resize();
		for (int i = 0; i < n; i++) {
			scanf("%lld",&x[i]);
		}
		getpre();
		solve();
		printf("%d\n",ret);
	}
}


