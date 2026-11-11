#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],box[200005],maxs=-1,f;
bool vis[200005];
void dfs(long long x){
	if(x==m+1){
		long long ans=box[1];
		for(long long i=2;i<=m;i++){
			ans=ans&box[i];
		}
		maxs=max(maxs,ans);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==0){
			box[x++]=a[i];
			vis[i]=1;
			dfs(x);
			vis[i]=0;
			x--;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(!f){
		cout<<1;
		return 0;
	}
	dfs(1);
	cout<<maxs;
	return 0;
}
