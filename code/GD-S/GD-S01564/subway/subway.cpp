#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=505,M=5e5+5;
int C,n,m,d,q,tw[M],k[N];
vector<PII>g[N+M];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar(); }
	return x*f;
}
int dijkstra(int st,int ed){
	priority_queue<PII,vector<PII>,greater<PII> >q;
	vector<int>dis(m+n+1,1e18);
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		PII f=q.top();
		q.pop();
		int u=f.second,dw=f.first;
		if(u==ed)return dis[u];
		if(dis[u]!=dw)continue;
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)tw[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a=read(),tim=read();
			g[i+m].push_back({a,tim});
			g[a].push_back({i+m,tim});
		}
	}
	for(int i=1;i<=q;i++){
		int xr=read(),yr=read();
		cout<<tw[xr]+tw[yr]+dijkstra(xr,yr)<<"\n";
	}
	return 0;
}
/*

*/
