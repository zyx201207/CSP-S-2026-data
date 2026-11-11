#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

typedef long long ll;

const int MAXN=2e5+5;

int c,t,n,edgeid=1,nxt[MAXN],head[MAXN],dis[MAXN],cnt[MAXN];

bool vis[MAXN];

ll d,ans,x[MAXN];

struct Road{
	int nxt,to;
}edge[MAXN];

struct Data{
	int now,val;
	bool operator <(const Data& tmp) const{
		return tmp.val<val;
	}
};

priority_queue <Data> Q;

inline void add_edge(int u,int v){
	edge[++edgeid]={head[u],v},head[u]=edgeid;
	return;
}

inline void Build_graph(){
	edgeid=1;
	for (int i=1;i<=n;i++) head[i]=0;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=nxt[i];j++) add_edge(i,j);
	}
	return;
}

inline void dij(int st){
	while (!Q.empty()) Q.pop();
	for (int i=st;i<=n;i++) dis[i]=inf,cnt[i]=0,vis[i]=0;
	dis[st]=0,cnt[st]=1,Q.push({st,0});
	while (!Q.empty()){
		Data tmp=Q.top();
		Q.pop();
		if (vis[tmp.now]) continue;
		vis[tmp.now]=1;
		for (int i=head[tmp.now];i;i=edge[i].nxt){
			int ed=edge[i].to;
			if (dis[tmp.now]+1>dis[ed]) continue;
			if (dis[tmp.now]+1<dis[ed]) cnt[ed]=cnt[tmp.now];
			else cnt[ed]+=cnt[tmp.now];
			dis[ed]=dis[tmp.now]+1;
			if (cnt[ed]>2) cnt[ed]=3;
			Q.push({ed,dis[ed]});
		}
	}
	for (int i=st;i<=n;i++) if (cnt[i]==2) ans++;
	return;
}

inline void subtask1(){
	Build_graph(),ans=0;
	for (int i=1;i<=n;i++) dij(i);
	return;
}

inline void prework(){
	scanf("%d%lld",&n,&d);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for (int i=1,j=0;i<=n;i++){
		j=max(j,i);
		while (j<n&&x[j+1]-x[i]<=d) j++;
		nxt[i]=j;
	}
	return;
}

inline void solve(){
	if (n<=5000) subtask1();
	else if (nxt[1]==n) ans=0;
	printf("%lld\n",ans);
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for (int i=1;i<=t;i++) prework(),solve();
	return 0;
}
