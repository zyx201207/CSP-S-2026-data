#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
struct sub { int xian,tim; };
int c,m,n,d,q,w[M];
ll mi,mp[N][N];
vector<sub> zh[M];
int main() {
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c >>n >>m >>d >>q;
	for (int i=1;i<=m;i++) {
		cin >>w[i];
	}
	for (int i=1,k;i<=n;i++) {
		cin >>k;
		for (int j=1,x,y;j<=k;j++) {
			cin >>x >>y;
			zh[x].push_back({i,y});
		//	node[i].push_back({x,y});
		}
	}
//	cout <<zh[2][0].xian << zh[2][0].tim <<"\n\n";
	memset(mp,0x3f,sizeof(mp));
	for (int x=1;x<=m;x++) {
		int l=zh[x].size();
		if (l>1) {
			for (int i=0;i<l;i++) {
				for (int j=i+1;j<l;j++) {
					mp[zh[x][i].xian][zh[x][j].xian]=zh[x][i].tim+zh[x][j].tim;
					mp[zh[x][j].xian][zh[x][i].xian]=zh[x][i].tim+zh[x][j].tim;
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		mp[i][i]=0;
	}
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (mp[i][j]>mp[i][k]+mp[k][j]) {
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
/*	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cout <<mp[i][j] <<" ";
		}
		cout <<"\n";
	}*/
	for (int i=1,u,v;i<=q;i++) {
		cin >>u >>v;
		mi=1e18;
		for (auto xu:zh[u]) {
			for (auto xv:zh[v]) {
				mi=min(mp[xu.xian][xv.xian]+w[u]+w[v]+xu.tim+xv.tim,mi);
			//	if (mp[xu.xian][xv.xian]+w[u]+w[v]+xu.tim+xv.tim==13) {
			//		cout <<xv.xian <<" " <<xv.tim <<"\n";
		//		}
			}
		}
		cout <<mi <<"\n" ;
	}
	return 0;
}

