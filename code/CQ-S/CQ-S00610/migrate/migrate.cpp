#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll c,t,n,d,en,ans,sum,Min;
ll a[N],vis[N];
vector<ll> e[N];
unordered_map<ll,ll> mp;
void dfs(ll x,ll step){
	if(x==en){
		mp[step]++;
		Min=min(Min,step);
		return;
	}
	if(step>Min) return;
	for(ll i=0;i<(ll)e[x].size();i++){
		if(vis[e[x][i]]) continue;
		vis[e[x][i]]=1;
		dfs(e[x][i],step+1);
		vis[e[x][i]]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(e,0,sizeof(e));
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				if(abs(a[i]-a[j])<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}else break;
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++){
				sum=0;
				Min=LLONG_MAX;
				mp.clear();
				en=j;
				dfs(i,0);
				if(mp[Min]==2) ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
