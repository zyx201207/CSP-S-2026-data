#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans1;
void dfs(int i2,int i1,int ans,int step){
	if(step>m){
		ans1=max(ans1,ans);
		return;
	}
	if(i2>n){
		return; 
	}
	ans=i1&ans;
	for(int i=i2+1;i<=n;i++){
		dfs(i,a[i],ans,step+1);
	}
	if(step==m){
		ans1=max(ans1,ans);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){;
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n-1;j++){
			dfs(j+1,a[i],a[j],2);
		}
	}
	cout<<ans1;
	return 0;
}
