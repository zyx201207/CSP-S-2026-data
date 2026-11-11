#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,ww;
	};
int c,n,m,d,q;
bool st[500505];
int w[500005],k[500005];
long long dis[500505];
vector<edge> e[50505];
int read(){
	int sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=sum*10+(ch-'0');
		ch=getchar();
	}
	return sum;
	}
long long spfa(int ss,int ed){
	memset(st,0,sizeof(st));
	for(int i=1;i<=m+n;i++) dis[i]=1e18;
	queue<int> q;
	q.push(ss);
	st[ss]=1;
	dis[ss]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		st[u]=0;
		int siz=e[u].size();
		for(int i=0;i<siz;i++){
			int v=e[u][i].to,s=e[u][i].ww;
			if(dis[v]>dis[u]+s){
				dis[v]=dis[u]+s;
				if(st[v]==0){
					q.push(v);
					st[v]=1;
				}
			}
		}
	}
	return dis[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			x=read();
			y=read();
			e[i].push_back({x+n,y});
			e[x+n].push_back({i,y});
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]+spfa(x+n,y+n));
	}
	return 0;
}
