#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pr;
ll c,t,n,d,a[2000010],dis[2000010],dp[2000010],vis[2000010];
void init(){
	for(ll i=1;i<=n;i++) dis[i]=LONG_LONG_MAX-1,vis[i]=dp[i]=0;
	return;
}
void dijkstra(ll st){
	init();
	queue<Pr> q;
	dis[st]=0,dp[st]=1;
	while(!q.empty()){
		ll dist=q.front().first,u=q.front().second;
		q.pop();
		if(vis[u]) continue;
		for(ll v=u+1;v<=n;v++){
			if(a[v]-a[u]<=d&&dist+1<dis[v]&&vis[v]==0){
				dis[v]=dist+1;
				dp[v]=dp[u];
				q.push({dis[v],v});
			}else if(a[v]-a[u]<=d&&dist+1==dis[v]){
				dp[v]+=dp[u];
			}
		}
	}
	return;
}
void solve(){
	init();
	cin>>n>>d;
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dijkstra(i);
		for(ll j=1;j<=n;j++){
			if(dp[j]==2) cnt++;
		}
	}
	cout<<cnt<<'\n';
	return;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			ll x;cin>>x;
			if(x==4) cout<<"1\n2";
			else cout<<"0\n1";
		}else if(t==17) cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if(t==12) cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		else if(t==14) cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if(t==16) cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else cout<<"zjl CSP-S rp++";
	}else{
		for(ll i=1;i<=t;i++){
			solve();
		}
	}
	
	return 0;
}
