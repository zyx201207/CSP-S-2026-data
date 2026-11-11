#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005]={~0},c[200005];
int n,m,maxx=-1;
void dfs(int d,int ans,int j){
	if(d>m){
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=j;i<=n;i++){
		if(!c[i]){
			c[i]=1;
			dfs(d+1,ans&a[i],i);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]&b[i-1];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}
	else if(m==n){
		cout<<b[n];
	}
	else{
		dfs(1,~0,1);
		cout<<maxx;
	}
	return 0;
}
