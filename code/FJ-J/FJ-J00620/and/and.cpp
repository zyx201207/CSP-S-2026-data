#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
void dfs(int x,int y,int z){
	if(y==m){
		if(ans<z){
			ans=z;
		}
		return;
	}
	if(x==n||z==0)return;
	for(int i=x+1;i<=n;i++){
		int tmp=z&a[i];
		dfs(i,y+1,tmp);
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
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
