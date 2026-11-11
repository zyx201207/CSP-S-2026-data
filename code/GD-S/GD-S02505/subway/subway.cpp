#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long c,n,m,d,p,ans[100005];
long a[N],dist[N];
bool f[N];
struct node{
	int sta,val;
};
struct node1{
	int v,ti;
};
vector<node>deg[N];
vector<node1>ln[510];
long long bfs(int u,int v){
	memset(f,0,sizeof(f));
	memset(dist,0,sizeof(dist));
	queue<int>q;
	q.push(u);
	f[u]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		int len=deg[now].size();
		for(int i=0;i<len;i++){
			if(!f[deg[now][i].sta]) q.push({deg[now][i].sta}),dist[deg[now][i].sta]=dist[now]+deg[now][i].val,f[deg[now][i].sta]=1;
			else dist[deg[now][i].sta]=min(dist[deg[now][i].sta],dist[now]+deg[now][i].val);
		}
	}
	return dist[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,t;
			cin>>u>>t;
			ln[i].push_back({u,t});
			for(int z=j-2;z>=0;z--){
				deg[u].push_back({ln[i][z].v,ln[i][z].ti+t});
				deg[ln[i][z].v].push_back({u,ln[i][z].ti+t});
			}
		}
	}
	for(int i=1;i<=p;i++){
		int ui,vi;
		cin>>ui>>vi;
		ans[i]=bfs(ui,vi)+a[ui]+a[vi];
	}
	for(int i=1;i<=p;i++) cout<<ans[i]<<endl;
	return 0;
}
