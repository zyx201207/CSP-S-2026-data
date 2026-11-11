#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n, m;
long long ans = 0;
void dfs(int u, long long cnt, int pre){
	if(u >= m){
		ans = max(ans, cnt);
		return;
	}
	for(int i = pre + 1; i <= n; i++){
		if(u == 0)
			dfs(u + 1, a[i], i);
		else
			dfs(u + 1, cnt & a[i], i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	if(m == 2){
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if(m == 1){
		for(int i = 1; i < n; i++){
			ans = max(ans, a[i]);
		}
		cout << ans;
		return 0;
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
} 
