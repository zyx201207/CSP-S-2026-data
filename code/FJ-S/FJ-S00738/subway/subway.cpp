#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500505],x,y,ans;
vector<ll> s[1005];
void bfs(){
	bool vis[500505];
	queue<ll> mq;
	mq.push(x);
	vis[x]=1;
	ll ans=0;
	while(!mq.empty()){
		ll o=mq.front();
		mq.pop();
		if(o==y){
			printf("%lld\n",&ans);
			break;
		}
		for(ll i=0;i<s[o].size();i++){
			mq.push(s[o][i]);
		}
	}
	return;
}
//bool vis[500505];
//void dfs(){
//	if(x==y){
//		printf("%lld\n",&ans);
//		return;
//	}
//	for(ll i=0;i<s[x].size();i++){
//		if(vis[s[x][i]])continue;
//		x=s[x][i];
//		ans+=w[x];
//		vis[x]=1;
//		dfs();
//		ans-=w[x];;
//		vis[x]=0;
//	}
//}
int main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway","w",stdout);
	scanf("%lld",&c);scanf("%lld",&n);scanf("%lld",&m);scanf("%lld",&d);scanf("%lld",&q);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(ll i=1;i<=n;i++){
		ll k;
		scanf("%lld",&k);
		for(ll j=1;j<=k;j++){
			ll a;
			scanf("%lld",&a);
			s[n+i].push_back(a);
			s[a].push_back(n+i);
		}
	}
	for(ll i=1;i<=2*n;i++){
	}
	while(q--){
		ans=0;
		scanf("%lld",&x);scanf("%lld",&y);
		bfs();
	}
	return 0;
}
