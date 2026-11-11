#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m;
int a[200100];
void dfs(int x, long long cnt,int k){
	if(k == m) {
		ans = max(ans,cnt);
		return;
	}
	if(x > n) return;
	dfs(x+1,cnt&a[x],k+1);
	dfs(x+1,cnt,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1,INT_MAX,0);
	cout << ans;
	return 0;
}
