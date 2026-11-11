#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>>a[500010];
int w[500010];
long long ed[510][510];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=m;i++)scanf("%d", &w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		while(k--){
			int s, t;
			scanf("%d%d", &s, &t);
			a[s].push_back({i, t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)ed[i][j]=1e18;
	for(int i=1;i<=m;i++)for(int j=1;j<a[i].size();j++)for(int k=0;k<j;k++)ed[a[i][j].first][a[i][k].first]=ed[a[i][k].first][a[i][j].first]=min(ed[a[i][j].first][a[i][k].first], (long long)a[i][j].second+a[i][k].second);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ed[i][j]=ed[j][i]=min(ed[i][j], ed[i][k]+ed[k][j]);
	while(q--){
		int x, y;long long ans=1e18;
		scanf("%d%d", &x, &y);
		for(int i=0;i<a[x].size();i++)for(int j=0;j<a[y].size();j++)ans=min(ans, ed[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second);
		printf("%lld\n", ans+w[x]+w[y]);
	}
	return 0;
}
