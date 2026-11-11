#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,inf=0x3f3f3f;
int c,n,m,d0,qq,d[N],w[N],k[510],vis[N];
int t[510][N];
int a[510][N];
vector<int> ve[N];
struct node {
	int d,u;
	bool operator > (const node a) const {
		return d<a.d;
	}
};
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d0,&qq);
//	c=read();n=read();m=read();d0=read();qq=read();
	for(int i=1; i<=m; i++) {
		scanf("%d",&w[i]);
		//w[i]=read();
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",&k[i]);
		//k[i]=read();
		for(int j=1; j<=k[i]; j++) {
			scanf("%d%d",&a[i][j],&t[i][j]);
			//a[i][j]=read();t[i][j]=read();
			ve[a[i][j]].push_back(i);//第i个地铁站被哪些线路经过
		}
	}
	while(qq--) {
		int x0,y0;
		scanf("%d%d",&x0,&y0);
		//x0=read();y0=read();
		priority_queue<node ,vector<node>,greater<node> > q;
		for(int i=1;i<=m;i++)d[i]=inf;
		for(int i=1;i<=m;i++)vis[i]=0;
		d[x0]=0;
		q.push((node) {
			0,x0
		});
		while(!q.empty()) {
			int u=q.top().u;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=0; i<ve[u].size(); i++) {
				int rail=ve[u][i];
				int cost=0;
				for(int j=1; j<=k[rail]; j++) {
					if(a[rail][j]==u) {
						cost=t[rail][j];
						//st=j;
						break;
					}
				}
				for(int j=1; j<=k[rail]; j++) {
					int y=a[rail][j];
					if(y==u)continue;
					if(vis[y])continue;
					if(d[y]>d[u]+t[rail][j]+cost) {
						d[y]=d[u]+t[rail][j]+cost;
						q.push((node) {
							d[y],y
						});
					}
				}
			}
		}
		printf("%d\n",d[y0]+w[x0]+w[y0]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
