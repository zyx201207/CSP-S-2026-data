#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q,k,x,y,t=1;
int w[250000],a[510][500005],t[510][500005],su[100000][510];
bool unite(int one,int two){
	for(int i=1;i<=n;i++){
		if(su[one][i]+su[two]==2) return true;
	}
}
int main(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		if(k!=2) t=0;
		for(int j=1;j<=k;j++){
			scanf("%d",&a[i][j],&t[i][j]);
		}
		su[a[i][j]][i]++;
	}
	while(q--){
		scanf("%d%d",&x,&y);
		if(t==1){
			
		}
		
	}
	return 0;
}
