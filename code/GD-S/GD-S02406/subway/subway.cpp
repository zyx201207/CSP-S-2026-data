#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dis[505][505];
int w[500005],a[500005],t[500005];
int s[500005][25];
int cst[500005][25];
int sn[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,-1,sizeof(dis));
	int c,n,m,d,q,p;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		scanf("%d",&p);
		for(int j=1;j<=p;j++){
			scanf("%d%d",&a[i],&t[i]);
			cst[a[i]][++sn[a[i]]]=t[i];
			s[a[i]][sn[a[i]]]=i;
		}
	}
	LL tdis;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sn[i];j++){
			for(int k=1;k<j;k++){
				tdis=cst[i][j]+cst[i][k];
				if(dis[s[i][j]][s[i][k]]==-1||tdis<dis[s[i][j]][s[i][k]]){
					dis[s[i][j]][s[i][k]]=dis[s[i][k]][s[i][j]]=tdis;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]>-1&&dis[k][j]>-1){
					if(dis[i][j]==-1){
						dis[i][j]=dis[i][k]+dis[k][j];
					}else{
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		}
	}
	int x,y;
	LL ans;
	while(q--){
		scanf("%d%d",&x,&y);
		ans=dis[s[x][1]][s[y][1]]+cst[x][1]+cst[y][1];
		for(int i=1;i<=sn[x];i++){
			for(int j=1;j<=sn[y];j++){
				ans=min(ans,dis[s[x][i]][s[y][j]]+cst[x][i]+cst[y][j]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
