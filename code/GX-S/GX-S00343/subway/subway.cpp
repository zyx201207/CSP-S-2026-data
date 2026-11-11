#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
int c,n,m,d,q,w[514514];
/*struct edge{
	int to,nxt,d;
}e[251314];
int head[514],tot=0;
void add(int u,int v,int d){
	e[++tot]=(edge){v,head[u],d};
	head[u]=tot;
	return;
}
*/
bool mp[505][20005];
int tim[505][20005];
int lmp[505][505],k[505],sta[505][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(lmp,0x3f,sizeof(lmp));
	for(int i=0;i<504;i++)lmp[i][i]=0;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&sta[i][j]);scanf("%d",&tim[i][sta[i][j]]);
			mp[i][sta[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int nw=sta[i][j];
			for(int ii=1;ii<=n;ii++){
				if(ii==i||!mp[ii][nw])continue;
				lmp[i][ii]=lmp[ii][i]=min(lmp[i][ii],tim[i][nw]+tim[ii][nw]);
			}
		}
	}
	//test:
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<lmp[i][j]<<' ';cout<<endl;}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k)continue;
				lmp[j][i]=lmp[i][j]=min(lmp[i][j],lmp[i][k]+lmp[j][k]);
			}
		}
	}
	while(q--){
		int st,ed;scanf("%d%d",&st,&ed);int ans=0x7777777f;
		int top1=0,qu1[20005],top2=0,qu2[20005];
		for(int i=1;i<=n;i++){
			if(mp[i][st])qu1[top1++]=i;
			if(mp[i][ed])qu2[top2++]=i;
		}
		for(int i=0;i<top1;i++){
			for(int j=0;j<top2;j++){
				ans=min(ans,w[st]+w[ed]+tim[qu1[i]][st]+tim[qu2[j]][ed]+lmp[qu1[i]][qu2[j]]);
				//cout<<w[st]<<' '<<w[ed]<<' '<<
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
