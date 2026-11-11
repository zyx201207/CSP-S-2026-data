#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 10;
const int M = 500 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
using namespace std;
inline ll read(){
	ll x=0, w=1;
	char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0' and c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
char c[100];
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	int cnt=0;
	do{
		c[++cnt]=x%10+'0';
		x/=10;
	}while(x);
	while(cnt)putchar(c[cnt--]);
	putchar('\n');
}

int n, m, d, q;

ll W[N];

struct Edge{
	int v;
	ll w;
	int nxt;
}e[N*40];
int ecnt,h[N+M];
void add(int u,int v,ll w){
	e[++ecnt]={v,w,h[u]};h[u]=ecnt;
}

ll dis[M][M];
ll ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		W[i]=read();
	}
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,x,t;j<=k;j++){
			x=read();t=read();
			add(i+m,x,t);
			add(x,i+m,t);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int e1=h[i],u;e1;e1=e[e1].nxt){
			u=e[e1].v-m;
			for(int e2=h[i],v;e2!=e1 and e2;e2=e[e2].nxt){
				v=e[e2].v-m;
				dis[u][v]=dis[v][u]=min(dis[u][v],e[e1].w+e[e2].w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k or dis[i][k]>=inf)continue;
			for(int j=1;j<=n;j++){
				if(i==j or j==k or dis[k][j]>=inf)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		x=read();y=read();
		ans=inf;
		for(int e1=h[x],u;e1;e1=e[e1].nxt){
			u=e[e1].v-m;
			for(int e2=h[y],v;e2;e2=e[e2].nxt){
				v=e[e2].v-m;
				ans=min(ans,e[e1].w+dis[u][v]+e[e2].w);
			}
		}
		write(ans+W[x]+W[y]);
	}
	return 0;
}
