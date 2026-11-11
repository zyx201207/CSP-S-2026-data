#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge{
	int to,next,w;
} e[2000010];
int head[500010],tot;
void add(int u,int v,int w){
	tot++;
	e[tot].to=v;e[tot].w=w;
	e[tot].next=head[u];
	head[u]=tot;
}

int c,n,m,d,q;
int k,a,t,tots;
int x,y;

int w[500010];
long long mind[500010];
bool vis[500010];


priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

long long minW(int x,int y){
	for (int i=1;i<=2*m+tots+100;i++){
		mind[i]=0x3f3f3f3f;vis[i]=0;
	}while (!pq.empty()){
		pq.pop();
	}
	pq.push({0,x});
	while (!pq.empty()){
		int mindd=pq.top().first,minp=pq.top().second;pq.pop();
		if (vis[minp])continue;
		vis[minp]=1;
		for (int i=head[minp];i;i=e[i].next){
			int nxt=e[i].to;
			if (mind[nxt]>mindd+e[i].w){
				mind[nxt]=mindd+e[i].w;
				pq.push({mind[nxt],nxt});
			}
		}
	}
	return mind[y];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
		add(i,m+i,w[i]);add(m+i,i,w[i]);
	}
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			tots++;
			cin>>a>>t;
			add(2*m+tots,a,t);add(a,2*m+tots,t);
			if (j!=1){
				add(2*m+tots-1,2*m+tots,0);
				add(2*m+tots,2*m+tots-1,0);
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<minW(x+m,y+m)<<"\n";
	}
	
	return 0;
}
