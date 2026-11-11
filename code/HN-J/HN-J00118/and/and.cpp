#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
bool vis[200005];
int maxn;
void dfs(int x,int ans){
	if(x == m + 1){
		maxn = max(maxn,ans);
		return;
	}
	if(ans == 0) return;
	for(int i = 1; i <= n; i ++){
		if(x == 1){
			vis[i] = 1;
			dfs(x + 1,a[i]);
			vis[i] = 0;
		}else{
			if(!vis[i]){
				vis[i] = 1;
				dfs(x + 1,ans & a[i]);
				vis[i] = 0;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(n > 20) maxn = max(maxn,a[i]);
	}
	if(n > 20) cout << maxn;
	dfs(1,1);
	cout << maxn;
	return 0;
}
