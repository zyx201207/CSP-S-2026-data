#include<bits/stdc++.h>
using namespace std;
long long n , m , a[200005] , vis[200005] , maxx = -1;
void dfs(int ans , int pos) {
	if(pos == m) {
		if(ans > maxx) maxx = ans;
		return ;
	}
	long long res = -1;
	for(int i = 1;i <= n;i++) {
		if(vis[i] == 0) res = max(res , (ans & a[i]));
	}
	for(int i = 1;i <= n;i++) {
		if(vis[i] == 0 && (ans & a[i]) == res) {
			vis[i] = 1;
			dfs(res , pos + 1);
			break;
		}
	}
}
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		memset(vis , 0 , sizeof(vis));
		vis[i] = 1;
		dfs(a[i] , 1);
		vis[i] = 0;
	}
	cout << maxx;
	return 0;
}
