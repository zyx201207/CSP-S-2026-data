#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+200;
ll vis[N];
ll s[N];
ll n,m;
ll ans;
void dfs(ll sum,ll num,ll mot){
	if(sum>m){
		return;
	}else{
		ans=max(ans,num);
	}
	for(int i=1;i<=mot;i++){
		if(vis[i]==0){
			vis[i]=1;
			sum+=(s[mot]-s[i]);
			num++;
			dfs(sum,num,mot);
			num--;
			sum-=(s[mot]-s[i]);
			vis[i]=0;
		}
	}
}
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		dfs(0,0,i);
	}
	cout<<ans<<"\n";
	return 0;
} 
