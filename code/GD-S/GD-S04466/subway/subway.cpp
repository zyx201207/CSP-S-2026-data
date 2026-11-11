#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7;
int c,n,m,d,q;
int w[500005];
bool vis[500005];
int to[MAXN],t[MAXN],nex[MAXN],h[500005],cnt=0;
void add(int u,int v,int ti){
	to[cnt]=v;
	t[cnt]=ti;
	nex[cnt]=h[u];
	h[u]=cnt++;
}
long long bfs(int S,int T){
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >p;
	memset(vis,0,sizeof(vis));
	p.push({0,S});
	vis[S]=1;
	while(!p.empty()){
		pair<long long,int>tmp=p.top();p.pop();
		int u=tmp.second;
		long long dist=tmp.first;
//		if(u>m){
//			cout<<"line:"<<u-m<<" "<<dist<<"\n";
//		}else{
//			cout<<"state:"<<u<<" "<<dist<<"\n";
//		}
		if(u==T)return dist;
		for(int e=h[u];e;e=nex[e]){
			int v=to[e],ti=t[e];
			if(vis[v])continue;
			p.push({dist+ti,v});
			vis[v]=1;
		}
	}return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}for(int i=0;i<n;i++){
		int u,ti,k;
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%d%d",&u,&ti);
			add(m+i+1,u,ti);
			add(u,m+i+1,ti);
		}
	}
	for(int i=0;i<q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]+bfs(x,y));
	}
	return 0;
}
