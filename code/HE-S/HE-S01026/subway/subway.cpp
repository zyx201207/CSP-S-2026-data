#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[405],k[205],t[205][405],a[205][405],sum;
bool vis[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j]; 
			t[j][i]=t[i][j];
			vis[i][j]=vis[j][i]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(vis[x][y]==1){
			cout<<w[x]+w[y]<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
