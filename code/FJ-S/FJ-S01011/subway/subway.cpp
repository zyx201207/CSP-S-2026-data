#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define endl '\n'
using namespace std;
int read();
const int N=510,M=5e5+10,inf=1e18;
int c,n,m,d,q,w[M],dis[N][N];
vector<PII> e[M],e1[N];
priority_queue<PII,vector<PII>,greater<PII> > p;
inline void solve(int x) {
	for(int i=1;i<=n;i++) dis[x][i]=inf;
	dis[x][x]=0,p.push(make_pair(dis[x][x],x));
	while(!p.empty()) {
		int u=p.top().second;p.pop();
		for(int i=0;i<(int)e1[u].size();i++) {
			int v=e1[u][i].first,w1=e1[u][i].second;
			if(dis[x][v]>dis[x][u]+w1) {
				dis[x][v]=dis[x][u]+w1;
				p.push(make_pair(dis[x][v],v));
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) dis[i][j]=inf;
	}
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++) {
		dis[i][i]=0;
		int k=read();
		for(int j=1;j<=k;j++) {
			int v1=read(),w1=read();
			e[v1].push_back(make_pair(i,w1));
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=0;j<(int)e[i].size();j++) {
			for(int k=j+1;k<(int)e[i].size();k++) {
				int u1=e[i][j].first,v1=e[i][k].first;
				int w1=e[i][j].second+e[i][k].second;
				dis[u1][v1]=min(dis[u1][v1],w1);
				dis[v1][u1]=min(dis[v1][u1],w1);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) if(dis[i][j]!=inf) e1[i].push_back(make_pair(j,dis[i][j]));
	}
	for(int i=1;i<=n;i++) solve(i);
	while(q--) {
		int x=read(),y=read(),ans=inf;
		for(int i=0;i<(int)e[x].size();i++) {
			for(int j=0;j<(int)e[y].size();j++) {
				int u1=e[x][i].first,v1=e[y][j].first;
				ans=min(ans,e[x][i].second+e[y][j].second+dis[u1][v1]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
int read() {
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-') Cf=-1;}
	while(Cr>='0' && Cr<='9') {Ca=(Ca<<3)+(Ca<<1)+Cr-48,Cr=getchar();}
	return Ca*Cf;
}

