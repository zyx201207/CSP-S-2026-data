#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn,b[200005],vis[200006];
void dfs(int step){
	if(step==m){
		long long ans=b[0];
		cout<<b[0]<<' ';
		for(int i=1;i<m;i++){
			ans=(ans&b[i]);
		}
		maxn=max(maxn,ans);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[step]=a[i];
			dfs(step+1);
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
	dfs(0);
	cout<<maxn;
	return 0;
}
