#include <bits/stdc++.h>
using namespace std;
const int N=1e6+30,M=1e6+1010;
int head[N],nxt[M],to[M],w[M],cnt;
int c,n,m,d,q;
int spot;
void add(int x,int y,int z){
	nxt[++cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	w[cnt]=z;
}
struct e{
	int v;
	long long w;
};
long long dij(int x,int y){
	bool vis[spot+10];
	long long dis[spot+10];
	for(int i=1;i<=spot;i++)vis[i]=0,dis[i]=1e18;
	queue<e> q;
	for(int i=head[x];i!=0;i=nxt[i]){
		q.push({to[i],w[i]});
		vis[to[i]]=1;
		dis[to[i]]=w[i];
	}
	while(!q.empty()){
		e tou=q.front();
		q.pop();
		for(int i=head[tou.v];i!=0;i=nxt[i]){
			int v2=to[i];
			dis[v2]=min(dis[v2],dis[tou.v]+w[i]);
			cout<<v2<<" "<<dis[v2]<<endl;
			if(!vis[v2]){
				q.push({v2,dis[v2]});
				vis[v2]=1;
			}
		}
	}
	return dis[y];
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	spot=2*m;
	for(int i=1;i<=m*2;i+=2){
		int w0;
		scanf("%d",&w0);
		add(i,i+1,w0);
		add(i+1,i,w0);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			spot+=1;
			add(spot,2*a-1,t);
			add(2*a-1,spot,t);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dij(2*x,y*2));
	}
	
	return 0;
}
