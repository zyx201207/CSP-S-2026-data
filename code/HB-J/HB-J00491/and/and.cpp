#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int mx=-1;
void dfs(int x,int y,int l){
	if(y==m){
		mx=max(mx,l);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(y==0)dfs(i,y+1,a[i]);
		else dfs(i,y+1,a[i]&l);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<mx;
	return 0;
}
