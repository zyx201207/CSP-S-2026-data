#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second 
const int N = 502,M = 1002;
int test_id,n,m,d,Q;
int out[M],dst[N+M][N+M];
map<int,int>t[N];
vector<int>sta[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&test_id);
	scanf("%lld%lld%lld%lld",&n,&m,&d,&Q);
	for(int i = 1;i<=m;i++)
		scanf("%lld",&out[i]);
	memset(dst,0x3f,sizeof(dst));
	for(int i = 1;i<=n;i++){
		int k,x,y;
		scanf("%lld",&k);
		for(int j = 1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			sta[x].push_back(i);
			dst[i][x+n] = dst[x+n][i] = y;
		}
	}
	for(int i = 1;i<n+m;i++)
		for(int j = i+1;j<=n+m;j++)
			for(int k = 1;k<=n+m;k++){
				if(i==j||j==k||i==k)
					continue;
				if(dst[i][j]>dst[i][k]+dst[k][j])
					dst[j][i] = dst[i][j] = dst[i][k]+dst[k][j];
			}
	while(Q--){
		int u,v;
		scanf("%lld%lld",&u,&v);
		int ans = out[u]+out[v]+dst[u+n][v+n];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
