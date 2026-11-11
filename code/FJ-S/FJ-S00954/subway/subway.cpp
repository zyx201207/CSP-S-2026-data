#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,a[505][505],t[505][505],maxx;
int w[500005],k[505],dp[505][505];
int dist[1005][1005];
int di[25005];
int pa[1005];
int paa[25005];
struct wq{
	int to,w;
};
vector<wq> vec[1005];
void dijkstra(int s){
	priority_queue<pair<int,int> >pq;
	memset(pa,0x3f,sizeof(pa));
	pq.push({0,s});
	while(!pq.empty()){
		int tq=pq.top().second;
		pq.pop();
		pa[tq]=1;
		for(int i = 0;i<vec[tq].size();i++){
			wq tt=vec[tq][i];
			if(pa[tt.to]==0 &&dist[tq][s]+tt.w>dist[tt.to][s]){
				dist[tt.to][s]=dist[tq][s]+tt.w;
				pa[tt.to]=1;
				pq.push({-dist[tt.to][s],tt.to});
			}
		}
	}
} 
int x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	memset(a,0x3f,sizeof(a));
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
		if(m<=1000)dist[i][i]=0;
	}
	if(m<505){
		for(int i = 1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j = 1;j<=k[i];j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
			}
		}
		for(int i = 1;i<=m;i++){
			dp[i][i]=0;
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=k[i];j++){
				//a[i][j]>>t[i][j];
				for(int z =1;z<=k[i];z++){
					if(a[i][j]!=a[i][z]){
						dp[a[i][j]][a[i][z]]=min(dp[a[i][j]][a[i][z]],t[i][j]+t[i][z]);
						/*
						if(==1&&z==2){
							cout<<dp[j][z]<<" "<<t[i][j]<<" "<<t[i][z]<<endl;
						}*/
					}
				}
			}
		}
		/*
		cout<<0x3f3f3f3f3f3f3f3f<<endl;
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=m;j++){
				if(dp[i][j]==0x3f3f3f3f3f3f3f3f)cout<<-1<<" ";
				else cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int k = 1;k<=m;k++){
			for(int i = 1;i<=m;i++){
				for(int j = 1;j<=m;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		for(int i = 1;i<=q;i++){
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",dp[x][y]+w[x]+w[y]);
		}
		return 0;
	}
	if(m<1005){
		maxx=0;
		for(int i = 1;i<=n;i++){
			scanf("%lld",&k[i]);
			for(int j = 1;j<=k[i];j++){
				scanf("%lld%lld",&a[i][j],&t[i][j]);
			}
			maxx=max(maxx,k[i]);
		}
		if(maxx<=2){
			for(int i = 1;i<=n;i++){
				if(k[i]==2){
					vec[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
					vec[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
				}
			}
			for(int i = 1;i<=m;i++){
				dijkstra(i);
			}
			for(int i = 1;i<=q;i++){
				scanf("%lld%lld",&x,&y);
				printf("%lld\n",dist[x][y]+w[x]+w[y]);
			}
		}
		return 0;
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

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
