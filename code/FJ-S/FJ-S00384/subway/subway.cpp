#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010],sum,ztf[500010],dtf[510];
struct T {
	int v;
	long long w;
};
vector<T> dt[510],zt[500010];
inline long long read() {
	long long x=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline void write(long long x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void dfs(int u,int f,int z,long long t) {
	if(f==1) {
		ztf[u]=t;
		if(u==z) {
			sum=min(sum,t);
			return;
		}
		for(T i:zt[u]) {
			if(dtf[i.v]<=t) continue;
			dfs(i.v,0,z,t+i.w);
		}
	} else {
		dtf[u]=t;
		for(T i:dt[u]) {
			if(ztf[i.v]<=t) continue;
			dfs(i.v,1,z,t+i.w);
		}
	}
	return;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1; i<=m; i++) w[i]=read();
	for(int i=1; i<=n; i++) {
		int k=read();
		for(int j=1; j<=k; j++) {
			int v=read();
			long long w=read();
			dt[i].push_back({v,w});
			zt[v].push_back({i,w});
		}
	}
	while(q--) {
		memset(ztf,0x3f3f3f3f,sizeof(ztf));
		memset(dtf,0x3f3f3f3f,sizeof(dtf));
		int x=read(),y=read();
		sum=4e18;
		dfs(x,1,y,0);
		sum+=w[x]+w[y];
		write(sum);
		putchar('\n');
	}
	return 0;
}
