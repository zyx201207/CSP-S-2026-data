#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]={};
int vis[200005]={};
int l[200005]={};
int ans=0;
void dfs(int k){
	if(k>m){
		int sum=l[1];
		for(int i=2;i<=m;i++){
			sum&=l[i];
		}
		ans=max(ans,sum);
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			else{
				vis[i]=1;
				l[k]=a[i];
				dfs(k+1);
				vis[i]=0;
			}
		}
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
