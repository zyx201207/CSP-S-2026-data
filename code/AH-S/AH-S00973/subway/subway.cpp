#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
long long c,n,m,d,q,a[M],k,num,id,val,l,r,vis[M][25][2],tot[M],dis[N][N],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
		scanf("%lld",&num);
		for(int j=1;j<=num;j++){
			scanf("%lld%lld",&id,&val);
			vis[id][++tot[id]][0]=i;
			vis[id][tot[id]][1]=val;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				dis[vis[i][j][0]][vis[i][k][0]]=dis[vis[i][k][0]][vis[i][j][0]]=min(dis[vis[i][k][0]][vis[i][j][0]],vis[i][j][1]+vis[i][k][1]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d %d %lld\n",i,j,mp[i][j]);
		}
	}*/
	//mp[1][2]=4,mp[2][3]=6,mp[3][4]=2,mp[1][4]=9,mp[2][4]=6;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d %d %lld\n",i,j,dis[i][j]);
		}
	}*/
	while(q--){
		ans=1e18;
		scanf("%lld%lld",&l,&r);
		for(int i=1;i<=tot[l];i++) for(int j=1;j<=tot[r];j++) ans=min(ans,dis[vis[l][i][0]][vis[r][j][0]]+vis[l][i][1]+vis[r][j][1]);
		printf("%lld\n",ans+a[l]+a[r]);
	}
	return 0;
}
