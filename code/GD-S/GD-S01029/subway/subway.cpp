#include<bits/stdc++.h>
using namespace std;
const int MAXN=500;
const int MAXM=5e5;
const long long INF=1e18;
int readint(void) {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
long long readll(void) {
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int c,n,m,d,q;
long long w[MAXM+10];
struct Node {
	int l;
	long long t;
};
vector<Node>a[MAXM+10];
int siz[MAXM+10];
long long dis[MAXN+10][MAXN+10];
int main(void) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=readint();
	n=readint();
	m=readint();
	d=readint();
	q=readint();
	for(int i=1; i<=m; i++) {
		w[i]=readll();
	}
	for(int i=1; i<=n; i++) {
		int k=readint();
		for(int j=1; j<=k; j++) {
			int id=readint();
			Node tmp;
			tmp.l=i;
			tmp.t=readll();
			a[id].push_back(tmp);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][j]=INF;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			dis[i][i]=0;
		}
	}
	for(int i=1; i<=m; i++) {
		siz[i]=a[i].size();
		for(int j=0; j<siz[i]; j++) {
			for(int k=j+1; k<siz[i]; k++) {
				dis[a[i][j].l][a[i][k].l]=dis[a[i][k].l][a[i][j].l]=min(dis[a[i][j].l][a[i][k].l],a[i][j].t+a[i][k].t);
			}
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			if(i!=k) {
				for(int j=1; j<=n; j++) {
					if(i!=j&&j!=k) {
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		}
	}
	while(q--) {
		int x=readint();
		int y=readint();
		long long ans=INF;
		for(int i=0; i<siz[x]; i++) {
			for(int j=0; j<siz[y]; j++) {
				ans=min(ans,w[x]+w[y]+a[x][i].t+a[y][j].t+dis[a[x][i].l][a[y][j].l]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
