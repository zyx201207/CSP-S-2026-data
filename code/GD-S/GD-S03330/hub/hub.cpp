#include<bits/stdc++.h>
#define il inline
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
#define vi vector<int>
#define vpii vector<pii>
#define pb push_back
#define mst(a,x) memset(a,x,sizeof a)
using namespace std;
const int N=1e6+10,INF=0x3f3f3f3f;
int C,n,k,id,hd[N],U[N],V[N];
struct EDGE {int to,ne;} e[N*2];
il void add(int u,int v) {e[++id]={v,hd[u]},hd[u]=id;}
namespace sol1 {
	const int N=5010;
	int d[N],X,s,t;
	void dfs1(int u,int fa) {
		if(!s||d[u]>d[s]) s=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs1(v,u);
	}
	void dfs2(int u,int fa) {
		if(!t||d[u]>d[t]) t=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs2(v,u);
	}
	int idx,L[N],R[N];
	vi vc,vt[N];
	void frt(int u,int fa) {
		L[u]=++idx,vt[d[u]].pb(u);
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) frt(v,u);
		R[u]=idx;
	}
	int ct[N],mx[N],A[N],B[N];
	void dfs3(int u,int fa) {
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) dfs3(v,u),mx[u]=max(mx[u],mx[v]+1);
		ct[mx[u]]++;
	}
	void sol() {
		int as=INF;
		for(int i=1;i<n;i++) {
			for(int j=0;j<=n;j++) d[j]=ct[j]=0;
			X=i,s=t=0;
			dfs1(U[i],V[i]);
			d[s]=0,dfs2(s,0);
			vc.clear();
			for(int j=0;j<=n;j++) vt[j].clear();
			idx=0,frt(s,0);
			for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
			int c=vc[vc.size()/2];
			for(int j=1;j<=n;j++) mx[j]=1;
			dfs3(c,0);
			for(int j=n;j;j--) A[j]=ct[j];
			for(int j=n-1;j;j--) A[j]+=A[j+1];
//			printf("%d %d\n",s,t);
			for(int j=0;j<=n;j++) ct[j]=0;
			s=t=0;
			dfs1(V[i],U[i]);
			d[s]=0,dfs2(s,0);
			vc.clear();
			for(int j=0;j<=n;j++) vt[j].clear();
			idx=0,frt(s,0);
			for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
			c=vc[vc.size()/2];
			dfs3(c,0);
			for(int j=n;j;j--) B[j]=ct[j];
			for(int j=n-1;j;j--) B[j]+=B[j+1];
//			printf("%d %d\n",s,t);
//			for(int j=1;j<=n;j++) printf("%d ",mx[j]); puts("");
			for(int j=0;j<n;j++) if(A[j+1]+B[j+1]<=k) {
				as=min(as,j);
//				printf("%d %d %d %d %d\n",U[i],V[i],j,A[j+1],B[j+1]);
				break;
			}
		}
		printf("%d\n",as);
	}
}
namespace sol2 {
	int f[N],g[N],h[N],hr[N];
	void dfs1(int u,int fa) {
		int fi=-1,se=-1;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa) {
			dfs1(v,u),f[u]=max(f[u],f[v]),h[u]=max(h[u],h[v]+1);
			if(h[v]>fi) se=fi,fi=h[v];
			else if(h[v]>se) se=h[v];
		}
		f[u]=max(f[u],fi+se+2);
	}
	il pii mg(pii x,int y) {
		if(y>x.fir) x.sec=x.fir,x.fir=y;
		else if(y>x.sec) x.sec=y;
		return x;
	}
	void dfs2(int u,int fa) {
		vi vc={0};
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa) vc.pb(v);
		int ln=vc.size()-1;
		vpii pr(ln+2),sf(ln+2);
		vi mp(ln+2),ms(ln+2);
		pr[0]={-1,-1},sf[ln+1]={-1,-1};
		for(int i=1;i<=ln;i++) pr[i]=mg(pr[i-1],h[vc[i]]),mp[i]=max(mp[i-1],f[vc[i]]);
		for(int i=ln;i;i--) sf[i]=mg(sf[i+1],h[vc[i]]),ms[i]=max(ms[i+1],f[vc[i]]);
		for(int i=1;i<=ln;i++) {
			g[vc[i]]=max({g[u],mp[i-1],ms[i+1]});
			g[vc[i]]=max(g[vc[i]],pr[i-1].fir+pr[i-1].sec+2);
			g[vc[i]]=max(g[vc[i]],sf[i+1].fir+sf[i+1].sec+2);
			g[vc[i]]=max(g[vc[i]],pr[i-1].fir+sf[i+1].fir+2);
			g[vc[i]]=max(g[vc[i]],max(pr[i-1].fir,sf[i+1].fir)+hr[u]+2);
			hr[vc[i]]=max({hr[u],pr[i-1].fir,sf[i+1].fir})+1;
			dfs2(vc[i],u);
		}
	}
	void sol() {
		for(int i=1;i<=n;i++) f[i]=g[i]=h[i]=0;
		dfs1(1,0),hr[1]=-1,dfs2(1,0);
		int as=INF;
		for(int i=2;i<=n;i++) {
			as=min(as,max(f[i]+1>>1,g[i]+1>>1));
//			printf("%d %d\n",f[i],g[i]);
		}
		printf("%d\n",as);
	}
}
namespace sol3 {
	int d[N],X,s,t;
	void dfs1(int u,int fa) {
		if(!s||d[u]>d[s]) s=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs1(v,u);
	}
	void dfs2(int u,int fa) {
		if(!t||d[u]>d[t]) t=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs2(v,u);
	}
	int idx,L[N],R[N];
	vi vc,vt[N];
	void frt(int u,int fa) {
		L[u]=++idx,vt[d[u]].pb(u);
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) frt(v,u);
		R[u]=idx;
	}
	int ct[N],mx[N],A[N],B[N];
	void dfs3(int u,int fa) {
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) dfs3(v,u),mx[u]=max(mx[u],mx[v]+1);
		ct[mx[u]]++;
	}
	void sol() {
		int as=INF;
		int m=n/2;
		for(int j=0;j<=n;j++) d[j]=ct[j]=0;
		X=m+1>>1;
		s=t=0;
		dfs1(U[X],V[X]);
		d[s]=0,dfs2(s,0);
		vc.clear();
		for(int j=0;j<=n;j++) vt[j].clear();
		idx=0,frt(s,0);
		for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
		int c=vc[vc.size()/2];
		for(int j=1;j<=n;j++) mx[j]=1;
		dfs3(c,0);
		for(int j=n;j;j--) A[j]=ct[j];
		for(int j=n-1;j;j--) A[j]+=A[j+1];
		for(int j=0;j<=n;j++) ct[j]=0;
		s=t=0;
		dfs1(V[X],U[X]);
		d[s]=0,dfs2(s,0);
		vc.clear();
		for(int j=0;j<=n;j++) vt[j].clear();
		idx=0,frt(s,0);
		for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
		c=vc[vc.size()/2];
		dfs3(c,0);
		for(int j=n;j;j--) B[j]=ct[j];
		for(int j=n-1;j;j--) B[j]+=B[j+1];
		for(int j=0;j<n;j++) if(A[j+1]+B[j+1]<=k) {
			as=min(as,j);
			break;
		}
		printf("%d\n",as);
	}
}

namespace sol4 {
	int d[N],X,s,t;
	void dfs1(int u,int fa) {
		if(!s||d[u]>d[s]) s=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs1(v,u);
	}
	void dfs2(int u,int fa) {
		if(!t||d[u]>d[t]) t=u;
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) d[v]=d[u]+1,dfs2(v,u);
	}
	int idx,L[N],R[N];
	vi vc,vt[N];
	void frt(int u,int fa) {
		L[u]=++idx,vt[d[u]].pb(u);
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) frt(v,u);
		R[u]=idx;
	}
	int ct[N],mx[N],A[N],B[N];
	void dfs3(int u,int fa) {
		for(int i=hd[u],v;i;i=e[i].ne) if((v=e[i].to)!=fa&&X!=(i+1>>1)) dfs3(v,u),mx[u]=max(mx[u],mx[v]+1);
		ct[mx[u]]++;
	}
	int fd() {
		X=0;
		for(int j=0;j<=n;j++) d[j]=ct[j]=0;
		s=t=0;
		dfs1(1,0);
		d[s]=0,dfs2(s,0);
		vc.clear();
		for(int j=0;j<=n;j++) vt[j].clear();
		idx=0,frt(s,0);
		for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
		int c=vc[vc.size()/2];
		return c;
	}
	mt19937_64 rnd(time(0));
	void sol() {
		int as=INF,cc=fd();
		vi vv;
		for(int _=hd[cc];_;_=e[_].ne) vv.pb(_);
		shuffle(vv.begin(),vv.end(),rnd);
		int qwq=0;
		for(int _:vv) {
			if(++qwq>100) break;
			X=_+1>>1;
			for(int j=0;j<=n;j++) d[j]=ct[j]=0;
			s=t=0;
			dfs1(U[X],V[X]);
//			printf("%d %d\n",U[X],V[X]);
			d[s]=0,dfs2(s,0);
			vc.clear();
			for(int j=0;j<=n;j++) vt[j].clear();
			idx=0,frt(s,0);
			for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
			int c=vc[vc.size()/2];
			for(int j=1;j<=n;j++) mx[j]=1;
			dfs3(c,0);
			for(int j=n;j;j--) A[j]=ct[j];
			for(int j=n-1;j;j--) A[j]+=A[j+1];
			for(int j=0;j<=n;j++) ct[j]=0;
			s=t=0;
			dfs1(V[X],U[X]);
			d[s]=0,dfs2(s,0);
			vc.clear();
			for(int j=0;j<=n;j++) vt[j].clear();
			idx=0,frt(s,0);
			for(int j=0;j<=n;j++) for(int u:vt[j]) if(L[u]<=L[t]&&R[t]<=R[u]) vc.pb(u);
			c=vc[vc.size()/2];
			dfs3(c,0);
			for(int j=n;j;j--) B[j]=ct[j];
			for(int j=n-1;j;j--) B[j]+=B[j+1];
			for(int j=0;j<n;j++) if(A[j+1]+B[j+1]<=k) {
				as=min(as,j);
				break;
			}
		}
		printf("%d\n",as);
	}
}
void QwQ() {
	scanf("%d%d",&n,&k);
	id=0;
	for(int i=1;i<=n;i++) hd[i]=0;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),U[i]=u,V[i]=v,add(u,v),add(v,u);
	if(C<=10) return sol1::sol();
	if(11<=C&&C<=12) return sol2::sol();
	if(13<=C&&C<=14) return sol3::sol();
	return sol4::sol();
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	scanf("%d%d",&C,&T);
	while(T--) QwQ();
}
/*
0 1
5 2
1 2
2 3
1 4
4 5

0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 2
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

