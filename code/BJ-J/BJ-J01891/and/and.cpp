#include<bits/stdc++.h>
using namespace std;
int v[200005];
int a[200005];
int n,m;
int ans=-1;
void dfs(int i,int j){
	if(j>m){
		int sum=v[1];
		for(int k=2;k<=m;k++){
			sum=sum&v[k];
		}
		ans=max(sum,ans);
		return;
	}
	if(i>n)return;
	v[j]=a[i];
	dfs(i+1,j+1);
	dfs(i+1,j);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
