#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],vis[200005],ans=-1;
void dfs(ll sum,ll pr,ll l){
	if(sum==m){
		ans=max(ans,pr);
		return;
	}
	for(int i=l;i<=n;i++){
		if(vis[i]!=1){
			vis[i]=1;
			if(sum!=0)
			dfs(sum+1,pr&a[i],i);
			else dfs(sum+1,a[i],i);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0,1);
	cout<<ans;
	return 0;
}
