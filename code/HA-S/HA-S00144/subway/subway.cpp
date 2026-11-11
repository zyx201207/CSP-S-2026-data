#include<bits/stdc++.h>
#define INF 0xffffffff
using namespace std;

int c,n,m,d,q;
long long w[1005];
vector<int> road[505];
vector<long long> tim[505];
vector<int> sta[25];
long long dp[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	long long x,y,k;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			road[i].push_back(x);
			tim[i].push_back(y);
			sta[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			dp[i][j]=INF;
		}
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			if(road[i].size()<2) continue;
			dp[road[i][0]][road[i][1]]=dp[road[i][1]][road[i][0]]=tim[i][0]+tim[i][1];
		}
	}
	else{
		for(int id=1;id<=n;id++){
			for(int i=0;i<road[id].size();i++){
				for(int j=0;j<road[id].size();j++){
					dp[road[id][i]][road[id][j]]=min(dp[road[id][i]][road[id][j]],tim[id][i]+tim[id][j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(i==j||i==k||j==k) continue;
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[j][i]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%lld\n",dp[x][y]+w[x]+w[y]);
	}
	return 0;
}
