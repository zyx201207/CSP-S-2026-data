#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c;
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}

const int N=5e5+5;
struct edge{
	int to,w;
};
vector<edge> g[3*N];
int c,d,qp;
int n,m;
int w[N]; 
int t[N]; 

typedef pair<int,int> P;
priority_queue<P,vector<P>,greater<P> > q;
int dis[3*N];
void dijkstra(int st){
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		P h=q.top();
		q.pop();
		int u=h.second;
		if(dis[u]>h.first) continue;
		for(auto e:g[u]){
			int v=e.to,w=e.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),qp=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	int cnt=2*m;
	for(int i=1,k;i<=n;i++){
		k=read();
		int a1,t1,a2,t2;
		a1=read(),t1=read();
		t[a1]++;
		int a1p=a1,a2p;
		if(t[a1]>1) a1p=++cnt;
		
		g[a1p].push_back({a1+m,t1});
		g[a1+m].push_back({a1p,t1});
		
		for(int j=2;j<=k;j++){
			a2=read(),t2=read();
			t[a2]++;
			a2p=a2;
			if(t[a2]>1) a2p=++cnt;
			
			g[a2p].push_back({a2+m,t2});
			g[a2+m].push_back({a2p,t2});
			
			g[a1p].push_back({a2p,0});
			g[a2p].push_back({a1p,0});
			
			a1=a2,a1p=a2p,t1=t2;
		}
	}
	for(int i=1,x,y,st,ed;i<=qp;i++){
		x=read(),y=read();
		st=x+m,ed=y+m;
		dijkstra(st);
		int ans=dis[ed];
		ans+=(w[x]+w[y]);
		write(ans);
		putchar('\n');
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
