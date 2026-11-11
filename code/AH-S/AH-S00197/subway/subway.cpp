#include<bits/stdc++.h>
using namespace std;
#define gc() getchar()
template<typename TP>
inline TP read(){
	TP f=1,x=0;char ch=gc();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=gc();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}
	return f*x;
}
typedef long long ll;
typedef pair<ll,int> PII;
const int N=1e6+505;
int n,casenum,cnt,S,T,qnum,d,m,tag;
ll dis[N];
int st[N];
struct edge{
	int to;ll w;
};
vector<edge> e[N];
void dijkstra(){
	++tag;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0*1ll,S});
	dis[S]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(st[u]==tag) continue;
		st[u]=tag;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].to;ll w=e[u][i].w;
			if(st[v]!=tag || dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
				if(v==T) return;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	casenum=read<int>();n=read<int>();m=read<int>();d=read<int>();qnum=read<int>();
	for(int i=1;i<=m;i++){
		ll w;
		w=read<ll>();
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		k=read<int>();
		for(int j=1;j<=k;j++){
			int ting;ll w;
			ting=m+read<int>();w=read<ll>();
			int tai=2*m+i;
			e[ting].push_back({tai,w});
			e[tai].push_back({ting,w});
		}
	}
	while(qnum--){
		S=read<int>();T=read<int>();
		dijkstra();
		printf("%lld\n",dis[T]);
	}
}
