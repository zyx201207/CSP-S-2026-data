#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[210000];
bool cmp(int a,int b){
	return a > b;
}
int ans = 0;int n,m; 
void dfs(int step,int sum,int z){
	if(z != 0 && z <= ans) return;
	if(n-step+1 < m-sum) return;
	if(step == n+1){
		if(sum != m) return;
		ans = max(ans,z);
		return;
	}
	if(sum == m) dfs(step+1,sum,z);
	int p = 0;
	if(z == 0) p = a[step];
	dfs(step+1,sum+1,((z+p)&a[step]));
	dfs(step+1,sum,z);
}
bool tb(int x){
	while(x%2 == 0) x/=2;
	return x == 1;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	cin>>n>>m;
	bool pd = 1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pd && !tb(a[i])) pd = 0;
	}
	sort(a+1,a+n+1,cmp);
	if(m == 1){
		//test #6 -- 5pts
		cout<<a[1];
		return 0;
	}
	if(pd){
		//special test A -- 5pts
		cout<<a[m];
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*

copy by baibai__

about 35 pts
*/
