#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=(1<<62)-1;
int n,m,a[200005],ans;
void dfs(int root,int g,int And){
	if(And<ans){
		return ;
	}
	if(root==n+1){
		if(g==m){
			if(And!=N){
				ans=max(ans,And);
			}
		}
		return ;
	}
	dfs(root+1,g,And);
	dfs(root+1,g+1,And&a[root]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,N);
	cout<<ans;
	return 0;
}
