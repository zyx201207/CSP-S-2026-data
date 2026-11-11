#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+50;
const int maxm = INT_MAX;
int dp[N];
int a[N];
int n;
int m;
int ans = 0;
void dfs(int dep, int tot, int cho){
	//cout << tot << endl;
	if(dep > n) return;
	if(cho > m) {
		ans = max(ans, tot);
		return;
	}
	//cout << dep<<' ';
	dfs(dep+1, tot&a[dep+1], cho+1);
	if(dep>0)
	dfs(dep+1, tot, cho);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		//dp[i]=(1<<31)-1LL;
	}
	dfs(1, a[1], 1);
	dfs(0, maxm, 0);
	cout << ans;
	
	return 0;
}
//5 3 31 3 1 15 7
//4 2 3 15 12 12
