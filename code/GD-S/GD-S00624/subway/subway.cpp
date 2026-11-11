#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5,M=505;
int Taskid;
ll n,m,d,Q;
ll fee[M][M],dis[M],more[N];
bool vis[M];
struct Edge{ ll v,w; };
vector<Edge>e[N],G[M]; 
struct node{ 
	ll u,w;
	bool operator > (const node &dt) const{
		return w>dt.w;
	}
};
priority_queue<node,vector<node>,greater<node> >q;
//=====================================================
void DIJ(ll st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,false,sizeof vis);
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		ll now=q.top().u; q.pop();
		if(vis[now]) continue;
		vis[now]=true;
		for(auto it:G[now]){
			ll nxt=it.v;
			if(dis[nxt]>dis[now]+it.w){
				dis[nxt]=dis[now]+it.w;
				q.push({nxt,dis[nxt]});
			}
		}
	} while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) fee[st][i]=dis[i];
}
//=====================================================
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>Taskid;
	cin>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>more[i];
	for(int i=1;i<=n;i++){
		ll len;
		cin>>len;
		for(int j=1;j<=len;j++){
			ll id,tim;
			cin>>id>>tim;
			e[id].push_back({i,tim});
		}
	}
	for(int i=1;i<=m;i++){
		ll len=e[i].size(),u=520,v=520,w=520;
//		for(auto it:e[i]) cout<<it.v<<' '<<it.w<<'\n';
		for(int j=0;j<len;j++)
			for(int k=j+1;k<len;k++){
				u=e[i][j].v,v=e[i][k].v,w=e[i][j].w+e[i][k].w;
//				cout<<"!!"<<u<<' '<<v<<' '<<w<<'\n';
				G[u].push_back({v,w});
				G[v].push_back({u,w});
			}
	}
	for(int i=1;i<=n;i++) DIJ(i); 
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			cout<<i<<"->"<<j<<": "<<fee[i][j]<<'\n';
	while(Q--){
		ll u,v;
		cin>>u>>v;
		ll ans=more[u]+more[v];
		ll res=LLONG_MAX;
		for(auto X:e[u]){
			for(auto Y:e[v])
				res=min(res,fee[X.v][Y.v]+X.w+Y.w);
		} cout<<ans+res<<'\n';
		
	}
	return 0;
} 
