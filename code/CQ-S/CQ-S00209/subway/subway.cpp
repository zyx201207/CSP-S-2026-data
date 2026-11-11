#include<iostream>
#include<vector>
using namespace std;
int cid;
int n,m,d,q;
long long w[500006];
long long dis[506][506];
vector<pair<int,long long> >vx[500006];
int main(){
//	system("fc subway.out subway7.ans");
//	return 0;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&cid,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			scanf("%d%lld",&a,&t);
			for(auto v:vx[a]){
				dis[v.first][i]=dis[i][v.first]=min(dis[v.first][i],v.second+t);
			}
			vx[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			printf("dis[%d][%d] = %lld\n",i,j,dis[i][j]);
//		}
//	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(auto v1:vx[x]){
			for(auto v2:vx[y]){
				ans=min(ans,dis[v1.first][v2.first]+v1.second+v2.second);
//				printf("%d -> %d\n",v1.first,v2.first); 
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
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
*/
