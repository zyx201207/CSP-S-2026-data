#include <bits/stdc++.h>
using namespace std;
int n, m;
long long r;
long long a[200005];
long long b[200005];
bool vis[200005];
long long s(){
	long long ans = b[1];
	for(int i = 2;i <= m;i++){
		ans &= b[i];
	}
	return ans;
}
int dfs(int x){
	if(x == m+1){
		long long t = s();
		return r = max(r, t);
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			b[x] = a[i];
			dfs(x+1);
			vis[i] = false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		long long maxn = -1;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(int i = 2;i <= n;i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		int ans = -1;
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				int t = (a[i]&a[j]);
				ans = max(ans, t);
			}
		}
		cout << ans;
		return 0;
	}
	cout << dfs(1);
	return 0;
}
