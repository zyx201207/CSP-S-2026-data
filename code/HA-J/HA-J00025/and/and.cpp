#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n, m, a[200005], ans;
bool vis[200005];
void dfs(int x, int now){
	if(x == 0){
		ans = max(ans, now);
		return;
	}
	bool xxx = (now == -1);
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		if(xxx)now = a[i];
		vis[i] = 1;
		dfs(x - 1, now & a[i]);
		vis[i] = 0;
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	dfs(m, -1);
	cout << ans;
	return 0;
}
