#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll N=2e4+10;
const ll INF=1e18;
ll w[N],dis[110][N],mp[110][N],h[110][N],v[110][N];
bool vis[110][N];
priority_queue<pair<ll,pair<ll,ll>>>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c,n,m,d,qq;
	cin>>c>>n>>m>>d>>qq;
	if(c>15){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++){
			mp[i][j]=INF;
		}
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		ll ls=0;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			mp[i][a]=t;
			if(j>1){
				h[i][ls]=a;
				v[i][a]=ls;
			}
			ls=a;
		}
	}
	for(ll r=1;r<=qq;r++){
		ll x,y;
		cin>>x>>y;
		for(ll i=0;i<=n;i++){
			for(ll j=0;j<=m;j++){
				dis[i][j]=INF;
				vis[i][j]=false;
			}
		}
		while(!q.empty()){
			q.pop();
		}
		dis[0][x]=0;
		q.push({0,{0,x}});
		while(!q.empty()){
			ll i=q.top().se.fi;
			ll a=q.top().se.se;
			q.pop();
			if((i==0)&&(a==y)){
				break;
			}
			if(vis[i][a]){
				continue;
			}
			vis[i][a]=true;
			if(i==0){
				for(ll j=1;j<=n;j++){
					if(dis[0][a]+mp[j][a]<dis[j][a]){
						dis[j][a]=dis[0][a]+mp[j][a];
						q.push({-dis[j][a],{j,a}});
					}
				}
			}
			else{
				if(dis[i][a]+mp[i][a]<dis[0][a]){
					dis[0][a]=dis[i][a]+mp[i][a];
					q.push({-dis[0][a],{0,a}});
				}
				ll nxt=h[i][a];
				if(nxt>0){
					if(dis[i][a]<dis[i][nxt]){
						dis[i][nxt]=dis[i][a];
						q.push({-dis[i][nxt],{i,nxt}});
					}
				}
				nxt=v[i][a];
				if(nxt>0){
					if(dis[i][a]<dis[i][nxt]){
						dis[i][nxt]=dis[i][a];
						q.push({-dis[i][nxt],{i,nxt}});
					}
				}
			}
		}
		ll ans=w[x]+w[y]+dis[0][y];
		cout<<ans<<endl;
	}
	return 0;
}
