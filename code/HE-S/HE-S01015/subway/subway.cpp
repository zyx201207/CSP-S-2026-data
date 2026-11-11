#include <bits/stdc++.h>
using namespace std;
const int N=1e3+4;
int c,n,m,d,q,k;
int w[N];
int t[504][N];
vector<int>a[504];
struct plan{
	int x,y;
}r[N];
long long dp[N][N];//dp[i][j]表示i号站厅到j号站厅的最短时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dp,127,sizeof(dp));
	for(int i=1;i<=m;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	} 
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int num;
			scanf("%d",&num);
			a[i].push_back(num);
			scanf("%d",&t[i][num]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&r[i].x,&r[i].y);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			for(int e=j+1;e<a[i].size();e++){
				dp[a[i][j]][a[i][e]]=t[i][a[i][j]]+t[i][a[i][e]];
				dp[a[i][e]][a[i][j]]=dp[a[i][j]][a[i][e]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]<=0x3fffffff){
				for(int e=1;e<=m;e++){
					if(dp[j][e]<=0x3fffffff){
						dp[i][e]=min(dp[i][e],dp[i][j]+dp[j][e]);
					}
				}
			}
		}
		
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",dp[r[i].x][r[i].y]+w[r[i].x]+w[r[i].y]);
	}
	
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
16:53 通过两个小样例
17:04 通过三个大样例 
我曾三度遭到背叛,因而懂得世间万物不过是欺瞒的幌子
唯有永恒,才最接近天理
唯有无念无想、无执无愿,才最接近永恒 
*/


