#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,x,y;
int k[500005];
int w[500005];
int a[5005][5005];
int t[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]);
	}
	return 0;
}
