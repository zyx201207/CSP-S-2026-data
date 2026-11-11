#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007],vis[200007],maxx=0;
void dfs(long long x,long long ans){
	
	if(x==m&&x>1){
		//cout<<ans<<" ";
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(x==0){
				dfs(x+1,a[i]);
			}else{
				dfs(x+1,ans&a[i]);
			}
			
			vis[i]=0;
		}
	}
}
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<maxx;
	return 0;
}
