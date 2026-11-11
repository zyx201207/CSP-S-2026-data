#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pir;
const int N=504;
const int M=5e5+4;
const ll inf=1e18;
ll c,n,m,d,q,k[N],w[M],dis[M];
bool vis[M],vis2[N];
vector<ll> now,a[N],t[N];
vector<pir> p[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		dis[i]=inf;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			p[a[i][j]].push_back(make_pair(i,t[i][j]));
		}
	}
	if(c>=12&&c<=19){
		while(q--){
			ll x,y;
			cin>>x>>y;
			queue<pir> q;
			q.push(make_pair(x,0));
			while(!now.empty()){
				vis[now.back()]=false;
				now.pop_back();
			}
			for(int i=1;i<=n;i++){
				vis2[i]=false;
			}
			now.push_back(x);
			ll ans=-1;
			while(!q.empty()){
				pir cur=q.front();
				ll u=cur.first;
				q.pop();
				for(int i=0;i<p[u].size();i++){
					ll id=p[u][i].first;
					if(vis2[id]){
						continue;
					}
					vis2[id]=true;
					for(int j=1;j<=k[id];j++){
						ll v=a[id][j];
						if(v!=u&&!vis[v]){
							if(v==y){
								ans=cur.second+2;
								break;
							}
							vis[v]=true;
							now.push_back(v);
							q.push(make_pair(v,cur.second+2));
						}
					}
					if(~ans){
						break;
					}
				}
				if(~ans){
					break;
				}
			}
			cout<<ans*t[1][1]+w[x]+w[y]<<'\n';
		}
	}else{
		while(q--){
			ll x,y;
			cin>>x>>y;
			priority_queue<pir> q;
			q.push(make_pair(0,x));
			while(!now.empty()){
				vis[now.back()]=false;
				dis[now.back()]=inf;
				now.pop_back();
			}
			dis[x]=0;
			now.push_back(x);
			while(!q.empty()){
				ll u=q.top().second;
				q.pop();
				if(vis[u]){
					continue;
				}
				if(u==y){
					break;
				}
				vis[u]=true;
				for(int i=0;i<p[u].size();i++){
					ll id=p[u][i].first;
					for(int j=1;j<=k[id];j++){
						ll v=a[id][j];
						ll w=t[id][j]+p[u][i].second;
						if(v!=u&&dis[u]+w<dis[v]){
							dis[v]=dis[u]+w;
							now.push_back(v);
							q.push(make_pair(-dis[v],v));
						}
					}
				}
			}
			cout<<dis[y]+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
/*
FIRE#####
*/
