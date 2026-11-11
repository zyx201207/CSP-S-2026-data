#include<bits/stdc++.h>
#define int long long
using namespace std;
int bg = 0,n,m,a[200010],mem[200010],vis[200010];
int dfs(int sum,int dep){
	if (mem[dep] != -1) return mem[dep];
	if (dep == m){
		if (sum > bg){
			bg = sum;
		}
	}
	for (int i = 1; i <= n; i ++){
		 if (!vis[i]){
		 	vis[i] = 1;
		 	mem[dep] = dfs(sum & a[i],dep + 1);
		 	vis[i] = 0;
		 }
	} 
	return mem[dep];
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	memset(mem,-1,sizeof mem);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++){
		dfs(a[i],0);
	}
	cout << bg << endl;
	return 0;
}


