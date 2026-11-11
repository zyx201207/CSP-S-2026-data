#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],key=0,ans,n,m;
bool vis[200005];
int INF=0x7f7f7f7f;
void dfs(int n,int k,int cur){
	if(k==0){
		ans=max(ans,cur);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(n,k-1,cur&a[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int minn=-10000000005;
		for(int i=1;i<=n;i++){
			minn=max(minn,a[i]);
		}
		cout<<minn;
	}
	else if(m==n-1){
		int minn=10000000005;
		for(int i=1;i<=n;i++){
			minn=min(minn,a[i]);
		}
		cout<<minn;
	}
	else if(n<20000){
		dfs(n,m,INF);
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		int x=INF;
		for(int i=n;i>=n-m+1;i--){
			x&=a[i];
		}
		cout<<x;
	}
	return 0;
}