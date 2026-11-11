#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005];
long long ans=-1;
int dfs(long long sum,int step){
	if(step<=0){
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(sum&a[i],step-1);
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
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(a[i],m-1);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
} 
