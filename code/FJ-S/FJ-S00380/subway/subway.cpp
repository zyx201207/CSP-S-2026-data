#include<bits/stdc++.h>
#define int long long
using namespace std;
int read() {
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct node {
	int s,t;
};
int c,n,m,d,q;
int w[500001];
vector<node>g[500001];
int dis[501][501];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)n<=300?scanf("%lld",&w[i]):w[i]=read();
	for(int i=1; i<=n; i++) {
		int k=read();
		for(int j=1; j<=k; j++) {
			int a,t;
			n<=300?scanf("%lld",&a):a=read();
			n<=300?scanf("%lld",&t):t=read();
			g[a].push_back({i,t});
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i!=j)
				dis[i][j]=LLONG_MAX;
	for(int i=1; i<=m; i++) {
		int len__=g[i].size();
		for(int j=0; j<len__; j++) {
			for(int k=j+1; k<len__; k++) {
				int u=g[i][j].s;
				int v=g[i][k].s;
				int w=g[i][j].t+g[i][k].t;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(dis[j][i]==LLONG_MAX)continue;
			for(int k=1; k<=n; k++) {
				if(dis[i][k]==LLONG_MAX)continue;
				dis[j][k]=min(dis[j][i]+dis[i][k],dis[j][k]);
			}
		}
	}
	while(q--) {
		int s,t;
		s=read();
		t=read();
		int ans=LLONG_MAX;
		int s_len=g[s].size();
		int t_len=g[t].size();
		for(int i=0; i<s_len; i++) {
			for(int j=0; j<t_len; j++) {
				int tot=w[s]+w[t]+g[s][i].t+g[t][j].t;
				tot+=dis[g[s][i].s][g[t][j].s];
				ans=min(tot,ans);
			}
		}
		printf("%lld\n",ans);
	}
}
