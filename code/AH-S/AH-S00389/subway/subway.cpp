#include <cstdio>
#include <vector>
#include <cstring>
#define re register
typedef unsigned long long LL;
template <typename T>
inline T read() {
	re T x=0; re char c; while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48); while((c=getchar())>'-');
	return x;
}
void write(LL x) {
	if(x>9) write(x/10);
	putchar(x%10|48);
}
inline void Min(LL &a,LL b) {if(a>b) a=b;}
const int N=5e5+5;
int w[N];
LL dis[505][505];
struct Node {
	short u; int t;
	Node(short a) : u(a),t(read<int>()) {};
};
std::vector<Node> line[N];
inline void Min(short x,short y,LL b) {
	if(dis[x][y]>b) dis[x][y]=dis[y][x]=b;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	short c,n,d; int m,q; scanf("%hd%hd%d%hd%d",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof dis);
	for(re int i=1;i<=n;++i) dis[i][i]=0;
	for(re int i=0;i!=m;w[++i]=read<int>());
	for(re short i=1;i<=n;++i) {
		int k=read<int>();
		while(k--) {
			int a=read<int>();
			line[a].emplace_back(i);
		}
	}
	for(re int u=0;u!=m;)
		for(auto i=line[++u].begin();i!=line[u].end();++i)
			for(auto j=i+1;j!=line[u].end();++j)
				Min(i->u,j->u,i->t+j->t);
	for(re short k=2;k<=n;++k)
		for(re short i=1;i<=n;++i)
			for(re short j=i+1;j<=n;++j)
				Min(i,j,dis[i][k]+dis[k][j]);
	while(q--) {
		int x=read<int>(),y=read<int>();
		LL ans=0x3f3f3f3f3f3f3f3f;
		for(auto i=line[x].begin();i!=line[x].end();++i)
			for(auto j=line[y].begin();j!=line[y].end();++j)
				Min(ans,i->t+j->t+dis[i->u][j->u]);
		write(ans+w[x]+w[y]),putchar(10);
	}
	return 0;
}
