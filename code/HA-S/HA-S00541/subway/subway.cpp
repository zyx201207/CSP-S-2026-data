#include <bits/stdc++.h>
using namespace std;
struct qxx{
	int to,w,nxt;
}g[5000010];int cnt,head[5000010];
void add(int u,int v,int w){
	g[++cnt].w=w;
	g[cnt].to=v;
	g[cnt].nxt=head[u];
	head[u]=cnt;
}
struct node{
	int u,d;
	bool operator<(const node &other)const{
		return other.d<d;
	}
};
int c,n,m,d,q,w[500010],dis[500010],k[500010],a[500010],t[500010];
priority_queue<node>qu;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=w[s];
	qu.push({s,dis[s]});
	while(!qu.empty()){
		int u=qu.top().u,dd=qu.top().d;
		qu.pop();
		if(dd>dis[u]) continue;
		for(int i=head[u];i;i=g[i].nxt){
			int v=g[i].to;
			if(dis[v]>dis[u]+g[i].w){
				dis[v]=dis[u]+g[i].w;
				qu.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j];
			cin>>t[j];
			for(int l=1;l<j;l++){
				add(a[l],a[j],t[l]+t[j]);
				add(a[j],a[l],t[l]+t[j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		dij(s);
		cout<<dis[t]+w[t]<<"\n";
	}
	return 0;
}

