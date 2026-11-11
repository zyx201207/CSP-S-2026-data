#include<bits/stdc++.h>//O2:100pts
using namespace std;
const int N=511;
const int M=5e5+111;
int a[M];
long long dp[N][N];
int t[N];
vector<pair<int,long long>>g[M];
int n,m,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d%d%d%*d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int len;
		scanf("%d",&len);
		for(int j=1;j<=len;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back({i,y});
		}
	}
	fill(dp[0],dp[0]+N*N,0x3f3f3f3f3f3f3f3f);
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<j;k++){
				dp[g[i][j].first][g[i][k].first]=min(dp[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
				dp[g[i][k].first][g[i][j].first]=min(dp[g[i][k].first][g[i][j].first],g[i][j].second+g[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				ans=min(ans,g[x][i].second+dp[g[x][i].first][g[y][j].first]+g[y][j].second);
			}
		}
		printf("%lld\n",ans+a[x]+a[y]);
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

I love Yore_Snow!!!!

and I'm Aurelia_Veil

so please help me work out the problem!!!!

thanks!

评测机快一点快一点快一点快一点快一点快一点快一点快一点

卡过去卡过去卡过去卡过去卡过去卡过去卡过去卡过去 

洛谷蓝钩分数线低一点低一点低一点低一点低一点低一点低一点 

蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩蓝钩 

妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈妈 
*/
