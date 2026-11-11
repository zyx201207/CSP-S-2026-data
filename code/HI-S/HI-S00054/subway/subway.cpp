#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[50005],k,x,y,ls;
long long minn,ls1,dt[50005][505],lx[505][50005];
bool t[50005];
void dfs(int s,long long sum){
	if(s==y){
		minn=min(minn,sum);
		return ;
	}
	for(int j=1;j<=n;j++){
		t[s]=1;
		if(dt[s][j]){
			for(int l=1;l<=m;l++){
				if(!t[l]&&lx[j][l]){
					dfs(l,sum+lx[j][l]+dt[s][j]);
				}
			}
		}
		
		t[s]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&ls,&ls1);
			lx[i][ls]=ls1;
			dt[ls][i]=ls1;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		minn=INT_MAX;
		memset(t,0,sizeof(t));
		dfs(x,0);
		printf("%lld\n",minn+w[x]+w[y]);
	}
	return 0;
}
