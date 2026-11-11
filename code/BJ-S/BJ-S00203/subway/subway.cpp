#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mk make_pair
#define fi first
#define sc second
#define int long long
using namespace std;
const int N=6e5;
int c,n,m,d,Q,uu,vv,ww,k1,ss[N],tt[N],ans[N];
int w[N];
vector<pii>nxt[N],query[N];
int dis[N];
bool vis[N];
priority_queue<pii,vector<pii>,greater<pii> >q;
void dij(int s){
	dis[s]=0;
	q.push(mk(0,s));
	while(!q.empty()){
		auto tmp=q.top();q.pop();
		if(vis[tmp.sc]==1)continue;
		vis[tmp.sc]=1;
//		cout<<tmp.sc<<":\n";
		for(auto to:nxt[tmp.sc]){
//			cout<<"  "<<to.fi<<'\n';
			if(dis[to.fi]>=dis[tmp.sc]+to.sc){
				dis[to.fi]=dis[tmp.sc]+to.sc;
				if(!vis[to.fi])q.push(mk(dis[to.fi],to.fi));
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>vv>>ww;
			nxt[m+i].pb(mk(vv,ww));
			nxt[vv].pb(mk(m+i,ww));
		}
	}
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=Q;i++){
		cin>>ss[i]>>tt[i];
		query[ss[i]].pb(mk(tt[i],i));
		query[tt[i]].pb(mk(ss[i],i));
	}
	for(int i=1;i<=Q;i++){
		if(ans[i]==-1){
			memset(vis,0,sizeof(vis));
			memset(dis,0x3f3f3f,sizeof(dis));
			dij(ss[i]);
			for(auto to:query[ss[i]]){
				if(ans[to.sc]==-1)ans[to.sc]=dis[to.fi]+w[ss[i]]+w[to.fi];
			}
		}
		cout<<ans[i]<<'\n';
	}
	return 0;
}
