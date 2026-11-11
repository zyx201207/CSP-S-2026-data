#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
const int M=1e5+10;
int c,n,m,d,q,k;
int w[N];
struct node{
	int to,w1;
	bool operator <(const node&n1) const{
		return n1.w1<w1;
	}
};
vector<node>v[N+M];
int dis[N+M];
bool vis[N+M];
int x,y;
void di(){
	priority_queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.to;
		int w=tmp.w1;
			if(vis[u]==1){
				continue;
			}
			vis[u]=1;
			for(int i=0;i<v[u].size();i++){
				int v1=v[u][i].to;
				if(v[u][i].w1+w<=dis[v1]){
					dis[v1]=v[u][i].w1+w;
					//cout<<u<<" "<<v1<<" "<<dis[v1]<<endl;
					q.push({v1,dis[v1]}); 
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[m+i].push_back({a,t});
			v[a].push_back({m+i,t});
		}
	}di[1]=0;
	di();
	for(int i=1;i<=q;i++){
		memset(dis,0x3f3f3f3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/

