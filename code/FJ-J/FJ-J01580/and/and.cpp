#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;

//and

int n,m;
int a[MAXN];
bool vis[MAXN];
long long ans = 0;

void dfs(int step,long long sum,int cnt) {
	if(step == n + 1 or cnt == m) {
		if(cnt == m) {
			ans = max(ans,sum);
		}
		return;
	}
	if(cnt == 0) {
		vis[step] = 1;
		dfs(step + 1,a[step],cnt + 1);
		vis[step] = 0;
	} else {
		vis[step] = true;
		dfs(step + 1,sum & a[step],cnt + 1);
		vis[step] = false;
	}
	if(n - step + 1 + cnt > m) dfs(step + 1,sum,cnt);
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool flag = true;
	bool flag_1 = false;
	
	cin >> n >> m;
	
	for(int i = 0;i <= 20;i++) {
		if(pow(2,i) == n) {
			flag_1 = true; 
			break;
		}
	}
	
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] != i - 1) flag_1 = false;
		if(flag) {
			bool fla = false;
			for(int j = 0;j <= 20;j++) {
				if(pow(2,j) - 1 == a[i]) {
					fla = true;
					break;	
				}
			}
			if(!fla) flag = false;
		}
	}
	
	if(m == 1) {
		int ans = INT_MIN;
		for(int i = 1;i <= n;i++) {
			ans = max(ans,a[i]);
		} cout << ans;
		return 0;
	}
	
	if(m == n) {
		int sum = a[1];
		for(int i = 2;i <= n;i++) {
			sum &= a[i];
		} cout << sum;
		return 0;
	}
	
	if(m == 2) {
		int ans = INT_MIN,x = 0,y = 0;
		for(int i = 1;i < n;i++) {
			for(int j = i + 1;j <= n;j++) {
				ans = max(ans,a[i] & a[j]);
			}
		} cout << ans;
		return 0;
	}
	
	if(flag) {
		sort(a + 1,a + n + 1);
		cout << a[n - m + 1];
		return 0;
	}
	
	if(flag_1) {
		int ans = n - 1;
		for(int i = 1;i <= m - 1;i++) {
			ans &= n - 1 - i;
		} cout << ans;
		return 0;
	}
	
	dfs(1,0,0);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

