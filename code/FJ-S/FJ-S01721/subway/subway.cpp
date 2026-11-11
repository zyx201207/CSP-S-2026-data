#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
struct node{
	int fa;
	int line;
	int val;
}p[N];
int cnt=0;
int st[N],ed[N];
struct edge{
	int u,v,val;
};
vector<vector<edge>> e[N];
//void bfs(int x,int y) return;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sybway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&p[++cnt].fa,&p[cnt].val);
			p[cnt].line=i;
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&st[i],&ed[i]);
		}
	}
	int nowline=p[1].line;
	for(int i=2;i<=cnt;i++){
		if(p[i].line==nowline){
			edge a;
			a.u=p[i-1].fa;
			a.v=p[i].fa;
			a.val=p[i-1].val+p[i].val;
			edge b;
			b.u=a.v;
			b.v=a.u;
			b.val=a.val;
			e[a.u].insert(a);
			e[b.u].insert(b);
		}
	}
	for(int i=1;i<=q;i++){
		int vall;
		for(auto j:e[i]){
			if(e[i][j].v==ed[j]) vall=e[i][j].val;	
		}
		cout<<w[st[i]]+w[ed[i]]+vall<<endl;
	}
	return 0;
}
