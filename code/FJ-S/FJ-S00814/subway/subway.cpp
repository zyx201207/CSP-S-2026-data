#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k,ans=0,x,y;
int v,u;
bool f;
int w[1005];
int aa[1005][1005];
int fa[20005];
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
			scanf("%d%d",&x,&y);
			aa[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%d%d",&u,&v);
		ans=ans+w[u]+w[v];
		for(int j=1;j<=n;j++){
			if(aa[j][u]!=0&&aa[j][v]!=0){
				ans=ans+aa[j][u]+aa[j][v];
				printf("%d\n",ans);
			}
		}	
	}
	return 0;
}
