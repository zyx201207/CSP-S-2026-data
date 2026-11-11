#include<bits/stdc++.h>
#define int long long
using namespace std;
void read(int &x){
	char y=getchar();
	bool fl=0;
	while(!('0'<=y && y<='9')){
		if(y=='-')fl=1;
		y=getchar();
	}
	x=0;
	while('0'<=y && y<='9'){
		x=(x<<3)+(x<<1)+y-'0';
		y=getchar();
	}
	if(fl)x=-x;
}
#define out(x) putchar(x)
void writ(const int &x){
	if(x<10){
		out(x+'0');
		return ;
	}
	writ(x/10);
	out(x%10+'0');
}
void write(const int &x){
	if(x==0)out('0');
	else if(x<0){
		out('-');
		writ(-x);
	}else writ(x);
}
const int N=5e5+5;
int c,n,m,d,q,w[N],k[N],u,v,uu,vv,fa[N],sum[N],tot;
struct node{
	int a,t;
};
vector<node>G[505];
//vector<int>nd[N];
int get(int x){
	if(x==fa[x])return x;
	int _=get(fa[x]);
	sum[x]+=sum[fa[x]];
	return fa[x]=_; 
}
bool merge(int u,int v,int w){
	uu=get(u);
	vv=get(v);
	if(uu==vv){
		sum[v]=min(sum[v],w);
		return 0;
	}
//	if(vv<=m){
		sum[vv]=sum[v]+w;
		fa[vv]=uu;
//		S[uu].push_back(vv);
//	}
	sum[v]=w;
	fa[v]=uu;
	return 1;
}
struct my_queue{
	int id,v;
};
vector<my_queue>Q[N];
int ans[N];
bool vis[N];
vector<int>S[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	tot=m;
	for(int i=1;i<=m;i++)fa[i]=i,sum[i]=0,S[i].push_back(i);
	for(int i=1;i<=n;i++){
		read(k[i]);
		for(int j=1;j<=k[i];j++){
			read(u);read(v);
//			nd[u].push_back(i);
			G[i].push_back({u,v});
//			merge(tot,u,v);
		}
	}
	for(int i=1;i<=q;i++){
		ans[i]=1e17;
		read(u);read(v);
		Q[u].push_back({i,v});
		Q[v].push_back({i,u});
//		uu=get(u);
//		vv=get(v);
//		write(sum[u]+sum[v]+w[u]+w[v]);
//		out('\n');
	}
	int nu,nv;
	for(int i=1;i<=n;i++){
		++tot;
		fa[tot]=tot,sum[tot]=0,S[tot].push_back(tot);
		for(int j=0;j<k[i];j++){
			merge(tot,G[i][j].a,G[i][j].t);
			for(my_queue l:Q[G[i][j].a])
				if(get(G[i][j].a)==get(l.v))ans[l.id]=min(ans[l.id],sum[G[i][j].a]+sum[l.v]+w[l.v]+w[G[i][j].a]);
//			merge(tot,u,v);
		}
//		for(int j=1;j<=m;j++)cout<<get(j)<<' ';
//		cout<<'\n';
	}
	for(int i=1;i<=q;i++){
		write(ans[i]);
		out('\n');
	}
	return 0;
}//I will win this game!!!
