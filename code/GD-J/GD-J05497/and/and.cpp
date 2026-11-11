#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+200;
ll vis[N];
ll f[N];
ll s[N];
ll all;
ll n,m;
void dfs(ll num){
	ll ans;
	if(num==m){
		ans=f[1];
		for(int i=2;i<=m;i++){
			ans=(ans&f[i]);
		}
		all=max(all,ans);
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				num++;
				f[num]=s[i];
				dfs(num);
				num--;
				vis[i]=0;
			}
		}
	}
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(0);
	cout<<all<<"\n";
	return 0;
}
