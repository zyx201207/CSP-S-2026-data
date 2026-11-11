#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
const int maxm=5e2+5;
const int maxx=4e6+5;
const int maxt=1e3+5;
int c, n, m, d, q, w[maxn], k[maxm], ans;
int tot, cnt, lbb[maxx<<1], jh[maxn], dis[maxt][maxt];
int zh[maxx], bj[maxx];
struct kk{
	int to, nxt, ww;
}gra[maxx<<1];
void add(int u, int v, int w){
	gra[++cnt]={v,lbb[u],w};
	lbb[u]=cnt;
}
struct ss{
	int type, dis, xid;
};
vector<ss> ll[maxn];
struct nn{
	int xid, val;
}lb;
struct mm{
	int s, t;
}f[maxn];
vector<nn> jl[maxm];
map<pair<int,int>,int> p;
inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct cc{
	int xid, dis;
}l_;
priority_queue<cc> qq;
bool operator<(cc k1, cc k2){
	return k1.dis>k2.dis;
}
void dij(int s){
	memset(zh,0x3f,sizeof(zh));
	memset(bj,0,sizeof(bj));
	zh[s]=0;
	qq.push({s,0});
	while(!qq.empty()){
		l_=qq.top();
		qq.pop();
		if(bj[l_.xid]) continue;
		bj[l_.xid]=1;
		for(int i=lbb[l_.xid];i;i=gra[i].nxt){
			int v=gra[i].to;
			if(zh[v]>zh[l_.xid]+gra[i].ww){
				zh[v]=zh[l_.xid]+gra[i].ww;
				qq.push({v,zh[v]});
			}
		}
	}
}
int dij(int s, int t){
	for(int i=1;i<=tot;i++){
		zh[i]=1e18;
		bj[i]=0;
	}
	zh[s]=0;
	qq.push({s,0});
	while(!qq.empty()){
		l_=qq.top();
		qq.pop();
		if(bj[l_.xid]) continue;
		bj[l_.xid]=1;
		for(int i=lbb[l_.xid];i;i=gra[i].nxt){
			int v=gra[i].to;
			if(zh[v]>zh[l_.xid]+gra[i].ww){
				zh[v]=zh[l_.xid]+gra[i].ww;
				qq.push({v,zh[v]});
			}
		}
	}
	return zh[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			lb.xid=read();
			lb.val=read();
			jl[i].push_back(lb);
			ll[lb.xid].push_back({i,lb.val,0});
		}
	}
	for(int i=1;i<=q;i++){
		f[i].s=read();
		f[i].t=read();
	}
	for(int i=1;i<=m;i++){
		int lk=ll[i].size();
		int lb=++tot;
		jh[i]=lb;
		for(int l=0;l<lk;l++){
			ll[i][l].xid=++tot;
			p[{ll[i][l].type,i}]=tot;
			add(lb,tot,ll[i][l].dis);
			add(tot,lb,ll[i][l].dis);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i]-2;j++){
			add(p[{i,jl[i][j].xid}],p[{i,jl[i][j+1].xid}],0);
			add(p[{i,jl[i][j+1].xid}],p[{i,jl[i][j].xid}],0);
			add(p[{i,jl[i][j].xid}],p[{i,jl[i][j-1].xid}],0);
			add(p[{i,jl[i][j-1].xid}],p[{i,jl[i][j].xid}],0);
		}
	}
	if(m<=1000){
		for(int i=1;i<=m;i++){
			dij(jh[i]);
			for(int j=1;j<=m;j++){
				dis[i][j]=zh[jh[j]];
			}
		}
		for(int i=1;i<=q;i++){
			write(w[f[i].s]+w[f[i].t]+dis[f[i].s][f[i].t]);
			putchar('\n');
		}
	}else{
		for(int i=1;i<=q;i++){
			write(w[f[i].s]+w[f[i].t]+dij(jh[f[i].s],jh[f[i].t]));
			putchar('\n');
		}
	}
	return 0;
}
/*
T:O(m^2)/O(mq)
M:
*/
