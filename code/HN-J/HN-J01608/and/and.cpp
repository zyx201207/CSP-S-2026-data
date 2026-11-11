#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[2005],ans;

void dfs(int res,int step){
	if(step==m+1){
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1; 
			dfs(res&a[i],step+1);
			vis[i]=0;
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
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)dfs(a[i],1);
		cout<<ans;
	}
}

