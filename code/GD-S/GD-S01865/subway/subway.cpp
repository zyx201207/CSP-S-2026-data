#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[200005][505],ans=0,minn=LONG_MAX;
bool bo[200005][505];
void dfs(int x,int j,int z){
	if(w[z][j]!=-1){
		ans+=w[z][j];
		minn=min(minn,ans);
		return ;
	}
	for(int i=1;i<=m;i++){
		if(i==x||w[i][j]==-1) continue;
		ans+=w[i][j];
		for(int k=1;k<=n;k++){
			if(w[i][k]==-1||k==j) continue;
			if(bo[i][k]==0){
				ans+=w[i][k];
				bo[i][k]=1;
				dfs(i,k,z);
				bo[i][k]=0;
			}
		}
	}
	return ;
}
int main(){
	memset(w,-1,sizeof(w));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
    	scanf("%lld",&w[i][0]);
	}
	for(int i=1;i<=n;i++){
		int op;
		scanf("%d",&op);
		for(int j=1;j<=op;j++){
			int p;
			scanf("%d",&p);
			scanf("%lld",&w[p][i]);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		minn=LONG_MAX;
		for(int i=1;i<=n;i++){
			ans=w[x][0]+w[y][0];
			if(w[x][i]==-1) continue;
			bo[x][i]=1;
			ans+=w[x][i];
			dfs(x,i,y);
		}
		printf("%lld\n",minn);
	}
	return 0;
}
