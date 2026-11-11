#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=520;
struct edge {
	int v,w,next;
}e[N<<2];
int cnt,h[N];
inline void add(int u,int v,int w) {
	e[++cnt]= {v,w,h[u]};
	h[u]=cnt;
}
int c,n,m,q,w[N];
ll d[M][M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof d);
	scanf("%d%d%d%d%d",&c,&n,&m,&c,&q);
	for(int i=1; i<=m; i++)
		scanf("%d",w+i);
	for(int i=1,k; i<=n; i++) {
		scanf("%d",&k);
		for(int j=1,a,t; j<=k; j++) {
			scanf("%d%d",&a,&t);
			add(i,a+M,t);
			add(a+M,i,t);
		}
	}
	for(int i=1; i<=n; i++)
		d[i][i]=0;
	for(int i=1; i<=m; i++) {
		for(int j=h[i+M]; j; j=e[j].next) {
			for(int k=h[i+M]; k; k=e[k].next) {
				int u=e[j].v,v=e[k].v;
				d[u][v]=d[v][u]=min(d[u][v],1LL*e[j].w+e[k].w);
			}
		}
	}
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++)
//			cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++)
//			cout<<d[i][j]<<' ';
//		cout<<endl;
//	}
	
	int s,t;
	while(q--) {
		scanf("%d%d",&s,&t);
		ll ans=1e18;
		for(int i=h[s+M]; i; i=e[i].next) {
			for(int j=h[t+M]; j; j=e[j].next)
				ans=min(ans,d[e[i].v][e[j].v]);
		}
		printf("%lld\n",ans+w[s]+w[t]);
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

*/
