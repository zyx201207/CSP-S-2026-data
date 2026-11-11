#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,k,s,t;
ll w[100005];
ll a[1005][505],dis[1005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i ++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			a[i][j] = 1e17;
		}
		for(int j = 1;j <= m;j ++){
			dis[i][j] = 1e17;
		}
		dis[i][i] = 0;
	}
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&k);
		for(int j = 1;j <= k;j ++){
			scanf("%lld%lld",&s,&t);
			a[s][i] = t;
		}
	}
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= m;i ++){
			for(int j = 1;j <= m;j ++){
				dis[i][j] = min(dis[i][j],a[i][k]+a[j][k]);
			}
		}
	}
	for(int k = 1;k <= m;k ++){
		for(int i = 1;i <= m;i ++){
			for(int j = 1;j <= m;j ++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	ll x,y;
	for(int i = 1;i <= q;i ++){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}

//qw:32pts

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16



*/
