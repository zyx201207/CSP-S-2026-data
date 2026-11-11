#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Node{
	int x,s;
	inline bool operator <(const Node &a)const{return s>a.s;}
};
struct Edge{int to,nxt,w;}e[505*1005<<1];
int c,n,m,d,Q,w[1005],a[505][1005],idx[505][1005],tot;
int pre[505*1005],rev[505*1005],head[505*1005],dist[505*1005],ct;
vector<int> appr[1005];
unordered_map<int,int> mp[505];
inline void link(int u,int v,int w){
	e[++ct]=(Edge){v,head[u],w};
	head[u]=ct;
}
inline int dijkstra(int x,int y){
	for(int i=1;i<=tot;i++)dist[i]=0x3f3f3f3f*(i!=x);
	priority_queue<Node> q;q.push((Node){x,0});
	while(!q.empty()){
		int u=q.top().x,s=q.top().s;q.pop();
		if(dist[u]<s)continue;
		if(rev[u]==y)return s;
		for(int i=head[u],v;i;i=e[i].nxt){
			if(dist[u]+e[i].w<dist[(v=e[i].to)]){
				dist[v]=dist[u]+e[i].w;
				q.push((Node){v,dist[v]});
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		idx[i][0]=++tot;
		for(int j=1,x;j<=k;j++){
			scanf("%d%d",&a[i][j],&x);
			idx[i][j]=++tot;
			for(int l=1;l<j;l++)link(idx[i][l],idx[i][j],x);
			mp[i][a[i][j]]=idx[i][j];
			pre[idx[i][j]]=x;
			appr[a[i][j]].push_back(i);
			rev[idx[i][j]]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(auto ix:mp[i]){
				if(mp[j].count(ix.first))link(ix.second,mp[j][ix.first],pre[mp[j][ix.first]]);
			}
		}
	}
	for(int i=1,x,y;i<=Q;i++){
		scanf("%d%d",&x,&y);
		int ans=w[x]+w[y],mn=0x3f3f3f3f;
		for(auto i:appr[x]){
			mn=min(mn,dijkstra(mp[i][x],y)+pre[mp[i][x]]);
		}
		printf("%d\n",mn+ans);
	}
}
