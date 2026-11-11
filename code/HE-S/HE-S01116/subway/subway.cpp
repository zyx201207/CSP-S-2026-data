#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int rd() {
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch-'0'); ch=getchar();}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-'), x=-x;
	if(x > 9) write(x/10); putchar(x%10+'0');
}
inline void wt(int x,char ch) {
	write(x); putchar(ch);
}
int c, n, m, d, q;
const int N = 5e5+7;
const int M = 507;
int w[N]; 
vector <pair<int,int> > has[N];
int dis[M][M];
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/ 
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for(int i=1;i<=m;i++) w[i] = rd();
	for(int i=1;i<=n;i++) {
		int k = rd();
		for(int j=1;j<=k;j++) {
			int v = rd(), w = rd();
			has[v].push_back({i,w});
		}
	}	  	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j] = 1e17; 
	for(int i=1;i<=n;i++) dis[i][i] = 0;
	for(int i=1;i<=m;i++) { 
		for(int j=0;j<has[i].size();j++) {
			int _1 = has[i][j].first, _1w = has[i][j].second;
			for(int k=j+1;k<has[i].size();k++) {
				int _2 = has[i][k].first, _2w = has[i][k].second;
				dis[_1][_2] = min(dis[_1][_2],_1w+_2w);
				dis[_2][_1] = min(dis[_2][_1],_1w+_2w);
			} 
		} 
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 
	while(q--) {
		int u = rd(), v = rd();
		int ans = 1e18;
		for(int i=0;i<has[u].size();i++) {
			int _1 = has[u][i].first, _1w = has[u][i].second;
			for(int j=0;j<has[v].size();j++) {
				int _2 = has[v][j].first, _2w = has[v][j].second;
				ans = min(ans,w[u]+w[v]+_1w+_2w+dis[_1][_2]);
			}
		} 
		wt(ans,'\n');
	}
	return 0;
}
