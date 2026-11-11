#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,idx;
int w[M],k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);;
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			scanf("%d%d",&aa,&tt);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=w[x]+w[y];
		printf("%d\n",ans);
	}
	return 0;
}
