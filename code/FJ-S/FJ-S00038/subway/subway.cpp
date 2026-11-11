/*#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,st[10001],a[500001],b[100001][20],f[100001][20];
vector<N>g[500001],h[500001];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}return x*f;
}
int main(){
	memset()
	c=read(),n=read(),m=read(),d=read(),p=read();
	for(int i=1;i<=m;i++)a[i]=read();
	for(long long i=1,x=0,y=0,z=0;i<=n;i++){
		x=read();
		for(int j=1;j<=x;j++){
			y=read(),z=read();
			g[y].push_back({i,z}),h[i].push_back({y,z});
		}
	}
	return 0;
} */

#include<bits/stdc++.h>
using namespace std;
//priority
inline long long read() {
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct N {
	long long x,y;
};
long long c,n,m,d,p,st[10001],a[500001],b[100001][20],f[100001][20];
vector<N>g[500001],h[500001];
long long dij(long long u,long long v) {
//	if(u>v)swap(u,v);
	for(int i=1;i<=n;i++)st[i]=1000000000;
	st[u]=a[u];
	priority_queue<pair<long long,long long>> q;
	q.push({-st[u],u});
	while(q.size()) {
		auto d=q.top();
		q.pop();
		long long dy=-d.first,dx=d.second;
//		cout<<dx<<" "<<dy<<" "<<g[dx].size()<<endl;
		for(long long i=0; i<g[dx].size(); i++) {
			for(long long j=0; j<h[g[dx][i].x].size(); j++) {
				long long dz=h[g[dx][i].x][j].y+g[dx][i].y;
//				cout<<dx<<" "<<dy<<" "<<dz<<" "<<st[h[g[dx][i].x][j].x]<<endl;
				if(dz+dy<st[h[g[dx][i].x][j].x]) {
					st[h[g[dx][i].x][j].x]=dz+dy;
					q.push({-st[h[g[dx][i].x][j].x],h[g[dx][i].x][j].x});
				}
			}
		}
	}
	return st[v]+a[v];
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),p=read();
//	if(c>6&&c<12) {
//		for(long long i=1,x=0,y=0,z=0; i<=n; i++) {
//			x=read();
//			for(int j=1; j<=x; j++) {
//				y=read(),z=read();
//				g[y].push_back({i,z}),h[i].push_back({y,z});
//			}
//		}
//		return 0;
//	}
	for(int i=1; i<=m; i++)a[i]=read();
	for(long long i=1,x=0,y=0,z=0; i<=n; i++) {
		x=read();
		for(int j=1; j<=x; j++) {
			y=read(),z=read();
			g[y].push_back({i,z}),h[i].push_back({y,z});
		}
	}
	for(int i=1; i<=p; i++) {
		cout<<dij(read(),read())<<endl;
	}
	return 0;
}  /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
