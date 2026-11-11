#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[200005],ans;
void dfs(int k,int ll){
	if(f[k]==1) return;
	if(k==m){
		ans=max(ans,ll);
		return;
	}
	for(int i=1;i<=n;i++){
		if(k==0){
			f[a[i]]=1;
			dfs(k+1,a[i]);///////////////////////////////////////////////////////////////
			f[a[i]]=0;
		}
		else if(f[a[i]]==0){
			f[a[i]]=1;
			dfs(k+1,ll&a[i]);
			f[a[i]]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}