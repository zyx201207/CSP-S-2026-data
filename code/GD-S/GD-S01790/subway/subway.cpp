#include<bits/stdc++.h>
#define N 500010
using namespace std;
//struct st{
//	int to,dist;
//}v[1010][1010];
int c,n1[N],n,m,d,q,x,y,a[N],b[N],w[N],k[N],dp[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=3||c>=7&&c<=11){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				dp[i][j]=1e9;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d",w+i);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",k+i);
			for(int j=1;j<=k[i];j++){
				scanf("%d%d",a+j,b+j);
			}
			for(int j=1;j<=k[i];j++){
				for(int kk=j+1;kk<=k[i];kk++){
					dp[a[j]][a[kk]]=min(dp[a[j]][a[kk]],b[kk]+b[j]);
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		while(q--){
			scanf("%d%d",&x,&y);
			printf("%d\n",w[x]+w[y]+dp[x][y]);
		}
	}
	return 0;
}
