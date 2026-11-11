#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500001], a[501][20001], t[501][20001], k[501];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) 
		cin>>w[i];
	for (int i=1;i<=n;i++) {
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for (; q--; ) {
		int x, y, sum=0;
		cin>>x>>y;
		int u=0, v=x;//  u是当前地铁线路编号   v是当前地铁站
		bool g=0;// 是否一命速通 
		for (int i=1;i<=n;i++) {//   这里的 i是地铁线路编号 
			for (int j=1;j<=k[i];j++) {//   这里的 j是此地铁线路的地铁站编号 
				if (a[i][j]==y && a[i][1]==x) {
					cout<<w[x]+t[i][x]+t[i][j]+w[j];
					g=1;
					break;
				}
			}
			if (g)
				break;
		}
		if (g)
			continue;
		
		
	}
	/*0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2*/
	return 0;
}

