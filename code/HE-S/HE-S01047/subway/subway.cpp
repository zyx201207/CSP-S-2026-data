#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int c,n,m,d,q;
ll w[N];
struct zhantai{
	int pl;
	ll cost;	
}t[N];
map<pair<int,int>,ll> mp;
vector<vector<int> > to(N);
bool vis[N];
queue<int>p;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>t[i].pl>>t[i].cost;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				int u=t[i].pl,v=t[j].pl;
				if(mp[{u,v}]==0){
					to[u].push_back(v);
					to[v].push_back(u);
				}
				if(mp[{u,v}]==0||mp[{u,v}]>t[i].cost+t[j].cost){
					mp[{u,v}]=t[i].cost+t[j].cost;
					mp[{v,u}]=t[i].cost+t[j].cost;
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(vis,0,sizeof(vis));
		while(!p.empty()) p.pop();
		vis[x]=1;
		for(int i=0;i<to[x].size();i++){
			p.push(to[x][i]);
			vis[to[x][i]]=1;
		}
		while(!p.empty()){
			int u=p.front();
			p.pop();
			for(int i=0;i<to[u].size();i++){
				int v=to[u][i];
				if(i==x) continue; 
				if(mp[{x,v}]==0){
					to[x].push_back(v);
					to[v].push_back(x);
				}
				bool f=0;
				if(mp[{x,v}]==0||mp[{x,v}]>mp[{x,u}]+mp[{u,v}]){
					mp[{x,v}]=mp[{x,u}]+mp[{u,v}];
					f=1;
				}
				if(!vis[v]&&f){
					vis[v]=1;
					p.push(v);
				}
			}
		}
		cout<<mp[{x,y}]+w[x]+w[y]<<'\n';
	}
	return 0;
}
