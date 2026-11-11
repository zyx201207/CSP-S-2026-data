#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005],b[200005],vis[200005];
long long aMax=0,ans,idx;

void dfs(long long x,long long sum,long long cnt){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(sum==-1){
			vis[i]=1;
			dfs(x+1,a[i],cnt+1);
			vis[i]=0;
			continue;
		}
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1,sum&a[i],cnt+1);
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
	dfs(0,-1,0);
	cout<<ans;
	return 0;
}
