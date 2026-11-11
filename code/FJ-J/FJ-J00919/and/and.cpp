#include <bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],vis[200005];
void dfs(int step){
	if(step > n){
		for(int i = 1;i <= n;i++){
			int lg = a[i];
			for(int j = i+1;j <= n + m - vis[i];j++){
				lg &= a[j];
				ans = max(ans,lg);
			}
		}
		return;
	}
	for(int i = 0;i <= 1;i++){
		vis[step] = i;
		dfs(step+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout << ans;
	return 0;
}
