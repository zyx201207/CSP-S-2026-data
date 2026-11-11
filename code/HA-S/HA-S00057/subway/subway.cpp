#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],tt[505][500005],have_x[500005][20],cnt[500005];
long long to_w[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		int ssss,ss;
		for(int j=1;j<=2*k[i];j++){
			scanf("%d",&ss);
			if(j%2==1)have_x[ss][++cnt[ss]]=i,ssss=ss;
			else tt[i][ssss]=ss;
		}
	}
	memset(to_w,0x3f,sizeof to_w);
	for(int i=1;i<=n;i++)to_w[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=cnt[i];j++)
			for(int kk=1;kk<=cnt[i];kk++){
				int xx=have_x[i][j],yy=have_x[i][kk];
				to_w[xx][yy]=min(to_w[xx][yy],1ll*tt[xx][i]+tt[yy][i]);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				to_w[i][j]=min(to_w[i][j],to_w[i][k]+to_w[k][j]);
	while(q--){
		int xx,yy;
		long long ans=0x3f3f3f3f3f3f3f3f;
		scanf("%d%d",&xx,&yy);
		for(int i=1;i<=cnt[xx];i++){
			for(int j=1;j<=cnt[yy];j++){
				int xxx=have_x[xx][i],yyy=have_x[yy][j];
				ans=min(ans,to_w[xxx][yyy]+tt[xxx][xx]+tt[yyy][yy]+w[xx]+w[yy]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
