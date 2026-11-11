#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200005];
int vis[200005];

void dfs(int k,int x){
	if(k>m){
		ans=max(ans,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(k==0){
				dfs(k+1,a[i]);
			}
			else{
				dfs(k+1,x&a[i]);
			}
			vis[i]=0;	
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
