#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int d[N];
int n,m;
int ans=0;
int dp[N][N];
void dfs(int sum,int gs,int pos){
	if (gs==m)
		ans=max(sum,ans);
	for (int i=pos;i<n;i++){
		if (sum == -1)
			dfs(d[i],gs+1,i+1);
		else 
			dfs(sum&d[i],gs+1,i+1);
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>d[i];
	dfs(-1,0,0);
	cout<<ans<<endl;
	return 0;
}
