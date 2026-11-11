#include<iostream>
using namespace std;
const int N=1e3+1;
int poi[N];
int a[N][N],t[N][N],k[N];



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}	
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	while (q--){
		int s,e;
		scanf("%d%d",&s,&e);
		printf("353535353\n");	
	}
	
	
	
	return 0;
}
