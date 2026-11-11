#include <bits/stdc++.h>
#define N 6005
using namespace std;
int i,j,k,x,y,n,v,u,c,d1,q;

int id[N][N];
int d[N][N];
int m;
int a[N];
int num;
int b[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d1,&q);
	for(i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		b[i]=num;
		for(j=1;j<=num;j++){
			scanf("%d%d",&id[i][j],&d[i][j]);
		} 
	}
	while(q--){
		
		scanf("%d%d",&x,&y);
		bool lz=false;
		int ans;
		for(i=1;i<=n;i++){
			if(id[i][x]!=0 && id[i][y]!=0){
				ans=i;
				lz=true;
				break;
			}
		} 
		if(lz){
			printf("%d\n",d[ans][x]+d[ans][y]);
		}
	}
	return 0;
}
