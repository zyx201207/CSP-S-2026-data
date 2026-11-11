#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int a[200005];
int ans, vis[200005];
void dfs(int u){
	if(u == n + 1){
		int sum = -1, cnt = 0;
		for(int i = 1; i <= n; i++){
			if(vis[i] == 1){
				cnt++;
				if(sum == -1) sum = a[i];
				else sum &= a[i];
			}
		}
		if(cnt == m) ans = max(ans, sum);
		return;
	}
	vis[u] = 1;
	dfs(u + 1);
	vis[u] = 0;
	dfs(u + 1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int Max = 0, Min = INT_MAX, b = 1;
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		Max = max(Max, a[i]);
		Min = min(Min, a[i]);
		if(a[i] >= 4) b = 0;
	}
	if(m == 1) cout << Max;
	else if(m == n){
		ans = a[1];
		for(int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
	}else if(b){
		int sum1 = 0, sum2 = 0, sum3 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == 1) sum1++;
			else if(a[i] == 2) sum2++;
			else if(a[i] == 3) sum3++;
		}
		if(sum3 >= m) cout << 3;
		else if(sum3 + sum2 >= m) cout << 2;
		else if(sum3 + sum1 >= m) cout << 1;
		else cout << 0; 
	}else if(n <= 20){
		dfs(1);
		cout << ans;
	}else cout << Min;
	return 0;
}
