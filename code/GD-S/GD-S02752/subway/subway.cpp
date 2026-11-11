#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ma=5e5+5;
struct Node{
	ll a,t;
};
struct Edge{
	ll v,w;
};
bool operator<(const Edge &a,const Edge &b){
	return a.w>b.w;
}
vector<Node>s[505];
vector<Edge>e[ma];
ll c,n,m,d,q,w[ma],dis[ma];
bool vis[ma];
void dji(ll s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	priority_queue<Edge>q;
	q.push({s,0});
	while(!q.empty()){
		int now=q.top().v;
		q.pop();
		if(vis[now])continue;
		else vis[now]=1;
		for(int i=0;i<e[now].size();i++){
			Edge nw=e[now][i];
			if(dis[nw.v]>dis[now]+nw.w){
				dis[nw.v]=dis[now]+nw.w;
				q.push({nw.v,dis[nw.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	priority_queue<Edge>qq;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			s[i].push_back({a,t});
			for(int q=0;q<s[i].size()-1;q++){
				e[s[i][q].a].push_back({a,s[i][q].t+t});
				e[a].push_back({s[i][q].a,s[i][q].t+t});
			}
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		dji(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
/*
*/
