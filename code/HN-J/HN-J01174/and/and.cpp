#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
bool vis[200001];
int ans;
void dfs(int step,int p,int op){
	if(op==n){
		if(step==m){
			ans=max(ans,p);
		}
		return ;
	}
	if(step==m){
		ans=max(ans,p);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(step==0){
				dfs(step+1,a[i],i);	
			}else{
				int s=p;
				s=s&a[i];
				dfs(step+1,s,i);
			}
			dfs(step,p,i);
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
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
