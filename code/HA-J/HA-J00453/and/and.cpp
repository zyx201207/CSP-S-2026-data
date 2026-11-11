#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n,m;
int ans = -1;
int a[N],num[N];
bool vis[N];

void dfs(int u){
	if (u == m){
		int temp = num[0];
		for (int i = 1;i<m;i++){
			temp = temp & num[i];
		}
		ans = max(ans, temp);
		return ;
	}
	for (int i = 0;i<n;i++){
		if (!vis[i]){
			vis[i] = true;
			num[u] = a[i];
			dfs(u+1);
			vis[i] = false;
		}
}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1;i<=n;i++) cin >> a[i];
	dfs(0);
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
