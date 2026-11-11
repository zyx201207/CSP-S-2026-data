#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N = 2e5 + 10;
int n, m, maxn = -2e9; 
int a[N]; 
bool vis[N];
void dfs(int s, int js){
	if(js > m)return;
	if(js == m)maxn = max(maxn, s);
	for(int i = 1; i <= n; i++){
		//cout << "i = " << i << " vis[i] = " << vis[i] << '\n';
		if(vis[i])continue;
		vis[i] = 1;
		//cout << s << " " << js << " " << a[i] << "\n"; 
		dfs((s & a[i]), js + 1); 
		vis[i] = 0;
	}
} 
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		vis[i] = 1;
		dfs(a[i], 1);
	}
	cout << maxn;
	return 0;
} 
