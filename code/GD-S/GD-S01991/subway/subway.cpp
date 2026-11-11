#include<bits/stdc++.h>
//以每个地铁线作为节点 
#define int long long
using namespace std;
const int M=5e5+10,N=505,inf=1e18+10;
int op,n,m,c,Q,w[M],d[N][N],dis[N][N],x,y,k[N],ans; 
bool vis[N];
struct node{
	int x,y;
	bool operator<(const node &A) const{return y>A.y;};
};
struct st{
	int x,y;
};
vector<node> ud[M];
vector<st> a[N];
vector<int> nxt[N];
void bfs(int st){
	priority_queue<node> q;
	q.push({st,0});
	for(int i=1;i<=n;i++) vis[i]=0;
	dis[st][st]=0;
	while(q.size()){
		node u=q.top();
		q.pop();
		if(vis[u.x]) continue;
		vis[u.x]=1;
		x=u.x;
		for(int i:nxt[x]){
			if(dis[st][i]>dis[st][x]+d[x][i]){
				dis[st][i]=dis[st][x]+d[x][i];
				q.push({i,dis[st][i]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>op>>n>>m>>c>>Q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			d[i][j]=d[j][i]=inf;
			dis[i][j]=dis[j][i]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		d[i][i]=dis[i][i]=0;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			ud[x].push_back({i,y});
			a[i].push_back({x,y});
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<ud[i].size();j++){
			for(int l=0;l<j;l++){
				int p=ud[i][j].x,q=ud[i][l].x;
				if(d[p][q]==inf){
					nxt[p].push_back(q);
					nxt[q].push_back(p);
				}
				d[p][q]=min(d[p][q],ud[i][j].y+ud[i][l].y);
				d[q][p]=d[p][q];
			}
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	while(Q--){
		cin>>x>>y;
		ans=inf;
		for(node i:ud[x]){
			for(node j:ud[y]){
				ans=min(ans,i.y+j.y+dis[i.x][j.x]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

