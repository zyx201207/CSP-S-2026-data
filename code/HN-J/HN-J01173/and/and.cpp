#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],da;
void dfs(int wz,int ans,int gs){
	if(gs==m){
		da=max(da,ans);
		return;	
	}
	if(wz==n) return;
	dfs(wz+1,ans&a[wz],gs+1);
	dfs(wz+1,ans,gs);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n-m;++i) dfs(i+1,a[i],1);
	cout<<da;
	return 0;
}
