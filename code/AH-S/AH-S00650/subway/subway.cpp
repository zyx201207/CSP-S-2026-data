#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
typedef struct Edge{
	int nxt,to;
	int d;
}Edge;
Edge edge[N*4];
int head[N],cnt=0;
int k[N],w[M][25],sta[M];
int c,n,m,d,q;
void addEdge(int u,int v,int d){
	cnt++;
	edge[cnt].nxt=head[u];
	edge[cnt].to=v;
	edge[cnt].d=d;
	head[u]=cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sta[i];
	}
	int a,t;
//	if(c>=7&&c<=11){
		int tempw=0,tempa=0;
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a>>t;
				if(j==2&&k[i]==2){
					addEdge(tempa,a,tempw+t);
					addEdge(a,tempa,tempw+t);
				}
				tempw=t,tempa=a;
			}
		}
		int u,v;
		int dis[M],vis[N];
		for(int i=1;i<=q;i++){
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			cin>>u>>v;
			queue<int> q;
			q.push(u);
			vis[u]=1;
			dis[u]=sta[u];
			int ans=INT_MAX;
			while(!q.empty()){
				int x;
				x=q.front();
				q.pop();
				for(int i=head[x];i;i=edge[i].nxt){
					int y=edge[i].to;
					int d=edge[i].d;
					if(!vis[y]&&dis[y]>dis[x]+d){
						dis[y]=dis[x]+d;
						if(y==v) {
							ans=min(dis[v]+sta[v],ans);
							continue;
						}
						vis[y]=true;
						q.push(y);
					}
				}
			}
			cout<<ans<<endl;
		}
//	}
	return 0;
}
