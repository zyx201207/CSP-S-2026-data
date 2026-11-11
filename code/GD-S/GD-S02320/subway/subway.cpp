#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pdd;
const int N = 505;
const int M = 5e5 + 31;

int c,n,m,d,q,w[M];
vector<pdd> vec[M];
ll f[N][N];

void gmin(ll &x,ll y){
	x = min(x,y);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++)
		scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++){
		int k; scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			int x,t; scanf("%d%d",&x,&t);
			vec[x].push_back(pdd(i,t));
		}
	}
	memset(f,63,sizeof(f));
	for(int i = 1;i <= m;i++){
		int len = vec[i].size();
		for(int u = 0;u < len;u++)
			for(int v = 0;v < len;v++) if(u != v)
				gmin(f[vec[i][u].first][vec[i][v].first],(ll)vec[i][u].second + vec[i][v].second);
	}
	for(int i = 1;i <= n;i++)
		f[i][i] = 0;
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				gmin(f[i][j],f[i][k] + f[k][j]);
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		ll ans = (1ll << 60);
		for(auto i : vec[x])
			for(auto j : vec[y])
				gmin(ans,f[i.first][j.first] + i.second + j.second);
		printf("%lld\n",ans + w[x] + w[y]);
	} 
}
