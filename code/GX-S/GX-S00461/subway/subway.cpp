#include<bits/stdc++.h>
using namespace std;
int sub,n,m,d,q,k[500010],t[1010][1010];
long long w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&sub,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=2*k[i];j++){
			scanf("%d",t[i][j]);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long cnt=w[x]+w[y];
		for(int i=x;i<=y;i++)cnt+=t[1][i];
		printf("%lld\n",cnt);
	}
	return 0;
}
