#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
void dfs(int x,int y,int z){
	if(y==m){
		ans=max(ans,z);
		return;
	}
	for(int i=x;i<=n;i++){	
		dfs(i+1,y+1,z&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i+1,1,a[i]);
	}
	cout<<ans;
	return 0;
}
