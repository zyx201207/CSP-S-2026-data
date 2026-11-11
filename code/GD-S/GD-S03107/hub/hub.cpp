#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
const ll N=2e4+10;
const ll INF=1e18;
vector<ll>kk[N];
ll pp[N],dis[N];
queue<ll>qq;
void dfs(ll x){
	for(auto s:kk[x]){
		if(pp[s]>=2){
			continue;
		}
		if(pp[s]==0){
			continue;
		}
		pp[s]+=2;
		dfs(s);
	}
}
void solve(ll c){
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		kk[i].clear();
	}
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		kk[u].push_back(v);
		kk[v].push_back(u);
	}
	if(c<=10){
		ll ans=INF;
		for(ll s=0;s<(1<<n);s++){
			ll res=0;
			for(ll i=1;i<=n;i++){
				pp[i]=0;
				dis[i]=INF;
			}
			ll cnt=0;
			for(ll i=0;i<n;i++){
				ll u=(s>>i)&1;
				if(u){
					cnt++;
					pp[i+1]=1;
					qq.push(i+1);
					dis[i+1]=0;
				}
			}
			if(cnt!=k){
				continue;
			}
			cnt=0;
			for(ll i=1;i<=n;i++){
				if(pp[i]>=2){
					continue;
				}
				if(pp[i]==0){
					continue;
				}
				pp[i]+=2;
				cnt++;
				dfs(i);
			}
			if(cnt>2){
				continue;
			}
			while(!qq.empty()){
				ll tmp=qq.front();
				qq.pop();
				for(auto s:kk[tmp]){
					if(dis[s]==INF){
						dis[s]=dis[tmp]+1;
						res=max(res,dis[s]);
						qq.push(s);
					}
				}
			}
			ans=min(ans,res);
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0<<endl;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		solve(c);
	}
	return 0;
}
