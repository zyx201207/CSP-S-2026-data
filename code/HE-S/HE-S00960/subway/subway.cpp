#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],x[100010],y[100010];
int a[510][500010],t[510][500010],k[500010];
int map[50010][50010];
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
			map[a[i][j]][a[i][j-1]]=1;
			map[a[i][j-1]][a[i][j]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",x[i],y[i]);
	}
	if(c>=8&&c<=11){
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
