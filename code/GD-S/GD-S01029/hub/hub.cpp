#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
const int INF=1e9;
int c,T,n,k;
int ce,hd[MAXN+10];
struct Edge {
	int to,nxt;
} e[(MAXN<<1)+10];
void add(int u,int v) {
	++ce;
	e[ce].to=v;
	e[ce].nxt=hd[u];
	hd[u]=ce;
	return;
}
bool sign[MAXN+10];
bool vis[MAXN+10];
void col(int u) {
	vis[u]=true;
	for(int i=hd[u]; i; i=e[i].nxt) {
		if(!vis[e[i].to]&&sign[e[i].to]) {
			col(e[i].to);
		}
	}
	return;
}
int d(int u,int lst) {
	if(sign[u]) {
		return 0;
	}
	int res=INF;
	for(int i=hd[u]; i; i=e[i].nxt) {
		if(e[i].to!=lst) {
			res=min(res,d(e[i].to,u)+1);
		}
	}
	return res;
}
int ans;
void dfs(int x,int c) {
	if(c>=k) {
		for(int i=1; i<=n; i++) {
			vis[i]=false;
		}
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(!vis[i]&&sign[i]) {
				if(cnt>=2) {
					return;
				}
				col(i);
				++cnt;
			}
		}
		int res=0;
		for(int i=1; i<=n; i++) {
			if(!sign[i]) {
				res=max(res,d(i,i));
			}
		}
		ans=min(ans,res);
		return;
	}
	if(x>n) {
		return;
	}
	sign[x]=true;
	dfs(x+1,c+1);
	sign[x]=false;
	dfs(x+1,c);
	return;
}
int rt1,rt2,lim,f[MAXN+10];
bool getrt1(int u,int lst) {
	for(int i=hd[u]; i; i=e[i].nxt) {
		if(e[i].to!=lst) {
			if(getrt1(e[i].to,u)) {
				return true;
			}
			f[u]=max(f[u],f[e[i].to]+1);
		}
	}
	if(f[u]>=lim) {
		rt1=u;
		return true;
	}
	return false;
}
bool getrt2(int u,int lst) {
	for(int i=hd[u]; i; i=e[i].nxt) {
		if(e[i].to!=lst) {
			if(getrt2(e[i].to,u)) {
				return true;
			}
			f[u]=max(f[u],f[e[i].to]+1);
		}
	}
	if(f[u]>=lim) {
		rt2=u;
		return true;
	}
	return false;
}
int dis[MAXN+10];
void getdis(int u,int lst) {
	for(int i=hd[u]; i; i=e[i].nxt) {
		if(e[i].to!=lst&&e[i].to!=rt1&&e[i].to!=rt2) {
			dis[e[i].to]=min(dis[e[i].to],dis[u]+1);
			getdis(e[i].to,u);
		}
	}
	return;
}
bool check(int mid) {
	lim=mid;
	rt1=0;
	rt2=0;
	for(int i=1; i<=n; i++) {
		f[i]=0;
	}
	if(!getrt1(1,0)) {
		return true;
	}
	for(int i=1; i<=n; i++) {
		f[i]=0;
	}
	if(!getrt2(rt1,0)) {
		return true;
	}
	for(int i=1; i<=n; i++) {
		dis[i]=INF;
	}
	dis[rt1]=0;
	dis[rt2]=0;
	getdis(rt1,0);
	getdis(rt2,0);
	for(int i=1; i<=n; i++) {
		if(dis[i]>lim) {
			return false;
		}
	}
	return true;
}
int m;
bool pd(int mid) {
	if(mid>=((m+1)>>1)) {
		return true;
	}
	int l=mid+1,r=m+1-mid;
	if(l+(k-2)>=r) {
		return true;
	}
	l=l+(k-2);
	int c=r-l;
	if((c>>1)<=mid){
		return true;
	}
	return false;
}
int main(void) {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c<=3) {
		while(T--) {
			for(int i=1 ; i<=n; i++) {
				hd[i]=0;
			}
			for(int i=1; i<=ce; i++) {
				e[i].to=0;
				e[i].nxt=0;
			}
			ce=0;
			scanf("%d%d",&n,&k);
			for(int i=1; i<n; i++) {
				int u,v;
				scanf("%d%d",&u,&v);
				add(u,v);
				add(v,u);
			}
			ans=INF;
			dfs(1,0);
			printf("%d\n",ans);
		}
	} else if(c==7||c==11||c==12) {
		while(T--) {
			for(int i=1; i<=n; i++) {
				hd[i]=0;
			}
			for(int i=1; i<=ce; i++) {
				e[i].to=0;
				e[i].nxt=0;
			}
			ce=0;
			scanf("%d%d",&n,&k);
			for(int i=1; i<n; i++) {
				int u,v;
				scanf("%d%d",&u,&v);
				add(u,v);
				add(v,u);
			}
			int l=0,r=n,res=n;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(check(mid)) {
					r=mid-1;
					res=mid;
				} else {
					l=mid+1;
				}
			}
			printf("%d\n",res);
		}
	} else if(c==13||c==14) {
		while(T--) {
			for(int i=1; i<=n; i++) {
				hd[i]=0;
			}
			for(int i=1; i<=ce; i++) {
				e[i].to=0;
				e[i].nxt=0;
			}
			ce=0;
			scanf("%d%d",&n,&k);
			for(int i=1; i<=n; i++) {
				int u,v;
				scanf("%d%d",&u,&v);
				add(u,v);
				add(v,u);
			}
			if(n==k) {
				printf("0\n");
			} else {
				m=((n+1)>>1);
				int l=1,r=n,res=n;
				while(l<=r) {
					int mid=(l+r)>>1;
					if(pd(mid)) {
						r=mid-1;
						res=mid;
					} else {
						l=mid+1;
					}
				}
				printf("%d\n",res);
			}
		}
	}
	return 0;
}
