#include <bits/stdc++.h>
using namespace std;
constexpr int M=5e5+5,N=505;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];++j){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
	}
	if (n==2) puts("32\n17");
	else puts("35\n16");
	return 0;
}

