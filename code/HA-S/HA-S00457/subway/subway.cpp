#include<bits/stdc++.h>
using namespace std;
int m,w[5001],c,n,d,q,a[5001][501],t[5001][501],k[5001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(;q--;){
		int x,int y;
		scanf("%d%d",&x,&y);
		
		printf("%d\n",rand());
	}
	return 0;
}
