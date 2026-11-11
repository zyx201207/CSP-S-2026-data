#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10005;
//struct Node{
//	int y,v;
//}node;
int c,n,m,d,q;
//vector<Node> arr[N];
int dp[N][N];
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(dp,127,sizeof(dp));
//	cout<<dp[1][1]<<endl;
	for(int i=1;i<=10000;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
//			node.v=t;
//			node.y=a;
//			arr[i+m].push_back(node);
			dp[i+m][a]=dp[a][i+m]=t;
		}
	}
	m=m+n;
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dp[i][k]!=2139062143&&dp[k][j]!=2139062143){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
}
