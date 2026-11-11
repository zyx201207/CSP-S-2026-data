#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200005],ans;
void dfs(int x,unsigned long long s,int k){
	if(n-k<m-x) return ;
	if(s<ans) return ;
	if(x==m){
		ans=max(ans,s);
		return ;
	}
	dfs(x,s,k+1);
	dfs(x+1,s&a[k],k+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,INT_MAX,1);
	cout<<ans;
	return 0;
}

