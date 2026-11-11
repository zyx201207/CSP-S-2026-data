#include<bits/stdc++.h>
using namespace std;
int a[505][505];
bool vis[505];
int c,n,m,d,q,step;
void dfs(int cur,int f,int s){
	if(cur==f){
		step=min(step,s);
		return;
	}
	for(int j=1;j<=d;j++){
		if(a[cur][j]!=0&&!vis[j]){
			vis[j]=1;
			dfs(j,f,s+a[cur][j]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);		
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	vector<int> w(m+1);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}		
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int aa,t;
			scanf("%d%d",&aa,&t);
			a[i][aa]=t;
			a[aa][i]=t;
		}
	}
	while(q--){
		step=INT_MAX;
		int x,y;
		scanf("%d%d",&x,&y);
		dfs(x,y,0);
		printf("%d\n",step+w[x]+w[y]);
		for(int i=0;i<505;i++){
			vis[i]=0;
		}
	}
	return 0;
}
