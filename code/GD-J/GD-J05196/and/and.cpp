#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+5;
using ll = long long;
int m, n;
int a[maxn]; 
bool vis[maxn];
ll ans = -1;
ll an = -1;
int can=0;
void dfs(int k){
	if (can >= m && k>=m){
		an = -1;
		for (int i=1;i<=n;i++){
			if (vis[i] == 0){
				if (an == -1);
					an = a[i];
				an = an&a[i];
			} 
		}
		ans = max(an, ans);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (vis[i]){
			vis[i] = 0;
			can++;
			
			dfs(k+1);
			
			can--;
			vis[i] = 1;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	memset(vis, 1, sizeof(vis));
	dfs(1);
	cout << ans;
	return 0;
}
/* ÖîÊÂË³, Àû */ 
