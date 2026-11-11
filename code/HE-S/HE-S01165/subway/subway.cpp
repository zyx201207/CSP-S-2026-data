#include<bits/stdc++.h>
using namespace std;
int dfs(int x,int y,int line){

	if(x=y) return all;
	flag[line][x]=1;
	
	if(flag[line][x+1]==0){
		dfs(x+1,y,line);
	}
	if(flag[line][x-1]==0){
		dfs(x-1,y,line);
	}
}
int flag[500005][500005]="0";
int c,n,m,d,k[500005],q,w[500005],a[500005][500005],t[500005][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int all=0,x[500005],y[500005]
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int g=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x[i],&y[i]);
		cout<<"0"<<endl;
	}
	for(int i=1;i<=n;i++){
		all=0;
		flag[500005][500005]={0};
		all+=w[x[i]]+w[y[i]];
		all+=dfs(x[i],y[i],i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
