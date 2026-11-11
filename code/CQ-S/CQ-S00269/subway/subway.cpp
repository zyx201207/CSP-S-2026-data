#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,x,y,w[500005],a[505][500005];
struct node {
	int l,step;
}s[500005];
int bfs(int h) {
	queue<node> pq;
	node u;
	u.l=h;
	u.step=0;
	pq.push(u);
	while(!pq.empty()) {
		node v=pq.front();
		if(v.l==y) return v.step;
		if(v.l>y) return 1e9;
		else {
			int p=v.l;
			for(int i=1;i<=n;i++) {
				if(a[i][p]!=0) {
					for(int j=p+1;j<=y;j++) {
						if(a[i][j]!=0) {
							node o={j,v.step+a[i][p]+a[i][j]};
							pq.push(o);
						}
					}
				}
			}
		}
	}
	return 1e9;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k); 
		for(int j=1;j<=k;j++) {
			int p,q;
			scanf("%d%d",&p,&q);
			a[i][p]=q;
		}
	}
	while(q--) {
		int x,y;
		long long ans=1e18;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++) {
			if(a[i][x]!=0&&a[i][y]!=0) {
				ans=min(ans,(long long)w[x]+w[y]+a[i][x]+a[i][y]);
			}
		}
		ans=min(ans,(long long)bfs(x)+w[x]+w[y]);
		printf("%d\n",ans);
	}
	return 0;
}
