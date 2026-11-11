#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 510,maxm = 5e5 + 10;
int w[maxm];
vector<array<int,2>> p[maxm];
ll dis[maxn][maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)scanf("%d",w+i);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		while(k--){
			int a,t;
			scanf("%d%d",&a,&t);
			p[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= n;i++){
		memset(dis[i]+1,0x3f,n << 3);
		dis[i][i] = 0;
	}
	for(int i = 1;i <= m;i++)
		for(auto[a,b]:p[i])
			for(auto[c,d]:p[i])
				dis[a][c] = min(dis[a][c],(ll)b + d);
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans = LLONG_MAX;
		for(auto[a,b]:p[x])
			for(auto[c,d]:p[y])
				ans = min(ans,b + dis[a][c] + d);
		printf("%lld\n",ans + w[x] + w[y]);
	}
}

