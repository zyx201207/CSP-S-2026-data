#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, M = 5e5+5;
const ll inf = 1e15;
int c, n, m, d, T, w[M], tim, k[N], pos, x, y, mp[N][M];
ll dis[M];
vector<int> a[N], t[N], p[N];
queue<int> q;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &T);
	for(int i=1;i<=m;i++) {
		scanf("%d", &w[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d", &k[i]);
		for(int j=0;j<k[i];j++) {
			scanf("%d%d", &pos, &tim);
			mp[i][pos]=j;
			p[pos].push_back(i);
			a[i].push_back(pos);
			t[i].push_back(tim);
		}
	}
	while(T--) {
		scanf("%d%d", &x, &y);
		for(int i=1;i<=m;i++) {
			dis[i]=inf;
		}
		q.push(x);
		dis[x]=0;
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			for(auto i:p[x]) {
				for(int j=0;j<k[i];j++) {
					int w=dis[x]+t[i][mp[i][x]]+t[i][j];
					if(dis[a[i][j]]>w) {
						dis[a[i][j]]=w;
						q.push(a[i][j]);
					}
				}
			}
		}
		printf("%lld\n", w[x]+dis[y]+w[y]);
	}
	return 0;
} 
