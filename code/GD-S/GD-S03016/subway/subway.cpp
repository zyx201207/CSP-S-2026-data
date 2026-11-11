#include<cstdio>
#include<vector>
using namespace std;
int min(int x,int y) { return x<y?x:y; }
const int inf=2147483647;
vector<int > a[500001];
vector<int > t[500001];
int C,n,m,d,q,ans=inf;
int w[500001],k[501],zb[501];
bool v[501];
//void dfs(int x,int y,int s,int h) {
//	printf("dfs(%d,%d,%d)\n",x,y,s);
//	if(x==y) {
//		ans=min(ans,s+w[x]);
//		return ;
//	}
//	v[x]=true;
//	for(int i=0;i<g[x].size();++i) {
//		if(!g[x][i]) dfs()
//	}
//	v[x]=false;
//	return ;
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i) {
		scanf("%d",&k[i]);
		for(int j=1,ls1,ls2,last=-1;j<=k[i];j++) {
			scanf("%d%d",&ls1,&ls2);
			a[j].push_back(ls1);
			t[j].push_back(ls2);
			zb[ls1]=j;
		}
	}
	for(int i=1,u,v;i<=q;++i) {
		ans=inf;
		scanf("%d%d",&u,&v);
		if(C>=12&&C<=19) {
			int bu=inf;
			for(int i=1;i<=n;++i) 
				bu=min(bu,(t[zb[u]][i-1]+t[zb[v]][i-1]));
			printf("%d\n",w[u]+w[v]+bu);
		} //Special B
		else {
//			dfs(u,v,w[u],0);
			printf("%d\n",ans);
		}
	}
	return 0;
} 
