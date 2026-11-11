#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000005],cnt[2000005],mi[2000005],vis[2000005];
ll bfs(ll s){
	ll ans=0;
	for(ll i=0;i<=n;i++) cnt[i]=0,vis[i]=0,mi[i]=1000000000000000000;
	queue<pair<ll,ll>> q;
	q.push({s,0});
	while(q.size()){
		ll v;
		ll u=q.front().first;
		ll l=q.front().second+1;
		q.pop();
		if(vis[u]>12) continue;
		if(u>=n) continue;
		for(v=u+1;x[v]-x[u]<=d&&v<=n;v++){
			if(l<mi[v]){
				mi[v]=l;
				cnt[v]=1;
			}else if(l==mi[v]){
				cnt[v]++;
			}
			q.push({v,l});
			if(l>=12) vis[v]++;
		}
	}
	for(ll i=s;i<=n;i++){
		if(cnt[i]==2) ans++;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans+=bfs(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
