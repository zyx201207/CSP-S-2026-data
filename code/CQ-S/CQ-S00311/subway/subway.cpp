#include<bits/stdc++.h>
#define int long long
using namespace std;
int bh,n,m,dd,t,w[500005],s[500005],dis[505][505];
const int inf=1e18;
struct edge{
	int y,z;
} ed[500005][25];
vector<edge> e[505];
struct node{
	int x,d;
};
bool operator < (node s1,node s2){
	return s1.d>s2.d;
}
priority_queue<node> q;
bool vis[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>bh>>n>>m>>dd>>t;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int sum,x,y; cin>>sum;
		for(int j=1;j<=sum;j++){
			cin>>x>>y;
			ed[x][++s[x]]={i,y};
		}
	}for(int i=1;i<=m;i++){
		for(int j=1;j<s[i];j++){
			for(int k=j+1;k<=s[i];k++){
				int x=ed[i][j].y,y=ed[i][k].y;
				int z=ed[i][j].z+ed[i][k].z;
				e[x].push_back({y,z});
				e[y].push_back({x,z});
			}
		}
	}for(int st=1;st<=n;st++){
		for(int i=1;i<=n;i++) 
			dis[st][i]=inf,vis[i]=false;
		dis[st][st]=0; q.push({st,0});
		while(!q.empty()){
			node u=q.top(); q.pop();
			if(vis[u.x]) continue;
			vis[u.x]=true;
			for(int i=0;i<e[u.x].size();i++){
				edge j=e[u.x][i];
				if(dis[st][j.y]<=dis[st][u.x]+j.z) continue;
				dis[st][j.y]=dis[st][u.x]+j.z;
				q.push({j.y,dis[st][j.y]});
			}
		}
	}while(t--){
		int x,y,ans=inf; cin>>x>>y;
		for(int i=1;i<=s[x];i++){
			edge ii=ed[x][i];
			for(int j=1;j<=s[y];j++){
				edge jj=ed[y][j];
				ans=min(ans,dis[ii.y][jj.y]+ii.z+jj.z);
			}
		}cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
