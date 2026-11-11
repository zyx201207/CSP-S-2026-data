#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],k[100005],x,y;
int xx[505][5005],yy[505][5005];
vector<int>a[505],b[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&xx[i][j],&yy[i][j]);
			a[i].push_back(xx[i][j]);
			b[xx[i][j]].push_back(i);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",w[x]+yy[1][x]+yy[1][y]+w[y]);
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

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
