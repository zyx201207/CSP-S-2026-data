#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int T;
int d,Q;
int nxt[500005],to[500005],hd[505],len[500005],cnt;
int nw;
void add(int u,int v,int w){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	len[cnt]=w;
	hd[u]=cnt;
}
int w[500005];
struct qry{
	int x,y,bh;
	friend bool operator>(qry a,qry b){
		return a.x>b.x;
	}
	friend bool operator<(qry a,qry b){
		return a.x<b.x;
	}
}qq[100005];
int dis[505];
const int inf=(1e18);
struct node{
	int dis,x,bh;
	node(int _dis=0,int _x=0){dis=_dis,x=_x;}
	friend bool operator<(node a,node b){return a.dis>b.dis;}
	friend bool operator>(node a,node b){return a.dis<b.dis;}
};
int anss[100005];
int bz[505];
struct db{
	int zt,d;
	db(int _zt=0,int _d=0){
		zt=_zt;
		d=_d;
	}
};
vector<db>v[500005];
int js[500005];
priority_queue<node>q;
void dij(int x){
	for(int i=1;i<=n;i++) dis[i]=inf;
	for(auto k:v[x]){
		dis[k.zt]=k.d;
		q.push(node(k.d,k.zt));
	}
	while(!q.empty()){
		int u=q.top().x;
		bz[u]=x;
		q.pop();
		for(int i=hd[u];i;i=nxt[i]){
			if(bz[to[i]]==x) continue;
			if(dis[u]+len[i]<dis[to[i]]){
				dis[to[i]]=dis[u]+len[i];
				q.push(node(dis[to[i]],to[i]));
			}
		}
	}
}
int dd[505][505];
char ch;
void read(int &x){
	ch=' ',x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
}
signed main()
{
//	freopen("subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(T),read(n),read(m),read(d),read(Q);
	for(int i=1;i<=m;i++) read(w[i]);
	nw=m;
	int kk;
	for(int i=1;i<=n;i++)
	{
		read(kk);
		int in1,in2;
		for(int j=1;j<=kk;j++)
		{
			read(in1),read(in2);
			v[in1].push_back(db(i,in2));
			js[in1]++;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dd[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<js[i];j++){
			for(auto k=j+1;k<js[i];k++){
				dd[v[i][j].zt][v[i][k].zt]=min(dd[v[i][j].zt][v[i][k].zt],v[i][j].d+v[i][k].d);
				dd[v[i][k].zt][v[i][j].zt]=min(dd[v[i][k].zt][v[i][j].zt],v[i][j].d+v[i][k].d);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++){
			if(dd[i][j]==inf) continue;
			add(i,j,dd[i][j]),add(j,i,dd[i][j]);
		}
	}
	for(int i=1;i<=Q;i++)
	{
		read(qq[i].x),read(qq[i].y);
		qq[i].bh=i;
	}
	sort(qq+1,qq+1+Q);
	int ls;
	for(int i=1;i<=Q;i++)
	{
		if(qq[i].x!=qq[i-1].x) dij(qq[i].x);
		ls=inf;
		for(auto k:v[qq[i].y]){
			if(dis[k.zt]==inf) continue;
			ls=min(ls,dis[k.zt]+k.d);
		}
		anss[qq[i].bh]=w[qq[i].x]+w[qq[i].y]+ls;
	}
	for(int i=1;i<=Q;i++) printf("%lld\n",anss[i]);
}
