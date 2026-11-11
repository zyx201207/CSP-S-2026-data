#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
ll n,m,ans=0;
ll a[200010];
void dfs(ll u,ll sum,ll cho){
	if(u>n || cho==m){
		if(cho==m)ans=max(ans,sum);
		return;
	}
	if(sum==0)dfs(u+1,a[u],cho+1);
	else dfs(u+1,(sum&a[u]),cho+1);
	dfs(u+1,sum,cho);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
