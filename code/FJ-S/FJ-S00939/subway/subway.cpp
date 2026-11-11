#include<bits/stdc++.h>
using namespace std;
const long long N=1005,M=6*1e5+5,inf=1e18;
long long c,n,m,d,qq,dist[N][N],ans,dis[N],f[N];
long long a[M],u,v,zk;
long long h[N],cnt;
struct hhh{
	long long t,k;
}p;
struct hhhh{
	long long t,ne,k;
}b[M];
vector<hhh> w[M];
struct node{
	long long id,k;
	bool operator <(const node &xx) const{
		return xx.k<k;
	}
}pp,ppp;
priority_queue<node> q;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void add(int x,int y,long long z){
	b[++cnt].ne=h[x];
	h[x]=cnt;
	b[cnt].t=y;
	b[cnt].k=z;
}
void dij(int x){
	for(int i=1;i<=n;i++){
		dis[i]=inf;f[i]=0;
	}
	dis[x]=0;
	pp.id=x;pp.k=0;
	q.push(pp);
	while(!q.empty()){
		pp=q.top();q.pop();
		u=pp.id;
		if(f[u]==1)continue;
		f[u]=1;
		for(int i=h[u];i;i=b[i].ne){
			if(f[b[i].t]==0&&dis[b[i].t]>dis[u]+b[i].k){
				dis[b[i].t]=dis[u]+b[i].k;
				ppp.id=b[i].t;ppp.k=dis[b[i].t];
				q.push(ppp);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dist[x][i]=dis[i];
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();qq=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	for(int i=1;i<=n;i++){
		u=read();
		for(int j=1;j<=u;j++){
			v=read();zk=read();
			p.t=i;p.k=zk;
			w[v].push_back(p);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	for(int now=1;now<=m;now++){
		for(int i=0;i<=(int)(w[now].size())-1;i++){
			for(int j=0;j<=(int)(w[now].size())-1;j++){
				if(i==j)continue;
				dist[w[now][i].t][w[now][j].t]=min(dist[w[now][i].t][w[now][j].t],w[now][i].k+w[now][j].k);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(dist[i][j]>=inf)continue;
			add(i,j,dist[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int o=1;o<=qq;o++){
		u=read();v=read();
		ans=inf;
		for(int i=0;i<=(int)(w[u].size())-1;i++){
			for(int j=0;j<=(int)(w[v].size())-1;j++){
				ans=min(ans,a[u]+a[v]+w[u][i].k+w[v][j].k+dist[w[u][i].t][w[v][j].t]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
