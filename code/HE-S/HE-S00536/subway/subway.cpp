#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=5e5+10;
const long long INF=1e18;
struct EDGE{int v,t;};
int c,n,m,dd,qq,w[M];
long long dis[M+N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
vector<EDGE> e[M+N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
void Dijkstra(int start){
	for(int i=1;i<=m+n;i++) dis[i]=INF;
	dis[start]=0;
	q.push({0,start});
	while(q.size()){
		int u=q.top().second,d=q.top().first;q.pop();
		if(d>dis[u]) continue;
		for(auto ed:e[u]){
			int v=ed.v,t=ed.t;
			if(dis[v]>dis[u]+t){
				dis[v]=dis[u]+t;
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();dd=read();qq=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int v=read(),t=read();
			e[i+m].push_back({v,t});
			e[v].push_back({i+m,t});
		}
	}
	for(int i=1;i<=qq;i++){
		while(q.size()) q.pop();
		int x=read(),y=read();
		Dijkstra(x);
		cout<<w[x]+dis[y]+w[y]<<'\n';
	}
	return 0;
}
