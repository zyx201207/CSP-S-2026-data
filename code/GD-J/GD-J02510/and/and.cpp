#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long a[maxn];
long long dp[2010][2010];
unsigned long long pre[2010];
bool use[50];
int n, m;
unsigned long long ans = 0;

struct node{
	long long num;
	string s;
}yuan[maxn];

bool cmp(node s1, node s2){
	return s1.s > s2.s;
}

void dfs(int ceng, int lst){
	if(ceng == m){
		unsigned long long nans = (unsigned long long)(1 << 31) - 1;
		for(int i = 1; i <= n; i++){
			if(use[i]){
				nans = nans & a[i];
			}
		}
		ans = max(ans, nans);
	}
	for(int i = lst + 1; i <= n; i++){
		if(!use[i]){
			use[i] = true;
			dfs(ceng + 1, i);
			use[i] = false;
		}
	}
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ma = -1;
	for(int i = 1; i <= n; i++){
		ma = max(ma, a[i]);
		dp[i][1] = ma;
	}
	if(m == 1){
		cout << ma;
	}else if(m == n){
		pre[0] = (unsigned long long)(1 << 31) - 1;
		for(int i = 1; i <= n; i++){
			pre[i] = pre[i - 1] & a[i];
		}
		cout << pre[m];
	}else if(n <= 20){
		dfs(0, 0);
		cout << ans;
	}else if(n <= 2010){
		for(int i = 1; i <= n; i++){
			for(int j = 2; j <= m; j++){
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]));
			}
		}
		cout << dp[n][m];
	}else{
		for(int i = 1; i <= n; i++){
			string ss = "";
			yuan[i].num = a[i];
			while(a[i]){
				if(a[i] & 1) ss += '1';
				else ss += '0';
				a[i] >>= 1;
			}
			reverse(ss.begin(), ss.end());
			yuan[i].s = ss;
		}
		sort(yuan + 1, yuan + n + 1, cmp);

		ans = (unsigned long long)(1 << 31) - 1;
		int bian = 0;
		for(int i = 1; i <= m; i++){
			ans = ans & yuan[i].num;
			if(ans == 0 && !bian){
				bian = i;
			}
		}
		cout << ans;
	}
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/

