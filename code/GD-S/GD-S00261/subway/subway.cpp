#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>
#define int long long
using namespace std;
struct abc{
	int id,node;
};
struct abc1{
	bool operator () (abc a,abc b){
		return a.node>b.node;
	}
};
priority_queue<abc,vector<abc>,abc1> que;
int w[5000005],top=0,dis[5000005],vis[5000005];
vector<pair<int,int>> vec[5000005];
void dij(int s){
	dis[s]=0;
	que.push({s,0});
	while(!que.empty()){
		int u=que.top().id,p=que.top().node;
		que.pop();
		vis[u]=1;
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].first,w=vec[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
			}
			if(!vis[v]) que.push({v,dis[v]});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	top=m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int now=top+1;
		top++;
		int fr=0;
		for(int i=1;i<=x;i++){
			int a,t;
			cin>>a>>t;
			if(fr==0){
				vec[++top].push_back({now,0});
				vec[now].push_back({top,0});
			}
			else{
				vec[++top].push_back({fr,0});
				vec[fr].push_back({top,0});
			}
			vec[top].push_back({a,t});
			vec[a].push_back({now,t});
		}
	}
	for(int i=1;i<=q;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 
