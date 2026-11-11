#include<bits/stdc++.h>
#define maxn 510
#define maxm 500010
#define maxd 30
#define ll long long
using namespace std;
ll mp[maxn][maxn];   //mp[i][j], i线路到j线路的最小路程 
ll w[maxm]; 
int to[maxm][maxd];  // 每个节点到达的线路
ll t[maxm][maxd];  //对应到达每个线路的长度 
int cnt[maxm];  //每个节点经过的线路数量 
ll query(int x, int y){
	ll res = 1e18;
	for(int i=1;i<=cnt[x];i++){
		for(int j=1;j<=cnt[y];j++){
			res = min(res, t[x][i]+t[y][j]+mp[to[x][i]][to[y][j]]);
		}
	}
	return res;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) mp[i][j] = 1e18;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld", &w[i]);
	}
	for(int i=1;i<=n;i++){
		int k, a;
		scanf("%d", &k);
		for(int j=1;j<=k;j++){
			scanf("%d", &a);
			to[a][++cnt[a]] = i; 
			scanf("%lld", &t[a][cnt[a]]);
		}
	}
	//对于每个节点，把他对应路线之间需要的长度建好 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				mp[to[i][j]][to[i][k]] = min(mp[to[i][j]][to[i][k]], t[i][j]+t[i][k]);
			}
		}
	}
//	floyd
	for(int jump=1;jump<=n;jump++){
		for(int i=1;i<=n;i++){
			if(mp[i][jump] == 1e18) continue;
			for(int j=1;j<=n;j++){
				if(mp[jump][j] == 1e18) continue;
				mp[i][j] = min(mp[i][j], mp[i][jump]+mp[jump][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;
	int x, y;
	while(q--){
		scanf("%d%d", &x, &y);
		printf("%lld\n", w[x]+w[y]+query(x, y));
	}
	return 0;
}
