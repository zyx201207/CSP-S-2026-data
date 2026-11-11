#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200001]={0},ans=0;
void dfs(ll i,ll z,ll sum){
	if(z==m){
		ans=max(ans,sum);
		return ;
	}
	if(i>n)return ;
	dfs(i+1,z+1,(sum==0?a[i]:sum&a[i]));
	dfs(i+1,z,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
}
