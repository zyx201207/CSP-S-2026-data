#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans;
void dfs(int s,int o,int h){
	if(h==m){
		ans=max(ans,s);
		return;
	}
	if(n-o+1<m-h){
		return;
	}
	if(h==0){
		dfs(s,o+1,h);
		dfs(a[o],o+1,h+1);
	}else{
		dfs(s,o+1,h);
		dfs(s&a[o],o+1,h+1);
	}
	
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(a[1],2,1);
	dfs(0,2,0);
	cout<<ans;
	return 0;
}
