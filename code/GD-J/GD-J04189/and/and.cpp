#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long b[200005];
bool vis[150005];
long long ans,res;
void dfs(int k){
	if(k==m+1){
		res=b[1];
		for(int i=2;i<=m;i++){
			res=res&b[i];
		}
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[k]=a[i];
			dfs(k+1);
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
	dfs(1);
	cout<<ans;
	return 0;
}
