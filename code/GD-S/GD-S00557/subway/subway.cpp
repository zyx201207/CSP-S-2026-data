#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1100];
int k;
vector<int> a[501];
int t[510][1100];
int x,y;
int zbh,ddd;
int dp[1100][1100];
int sj[1100][1100];

void solve(){
	int ans=1<<30;
	scanf("%d%d",&x,&y);
	memset(dp,127,sizeof(dp));
	for(auto hx:a[x]){
		dp[0][hx]=w[x]+t[hx][x];
	}
	for(int i=1;i<=m-1;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			for(int k=1;k<=m;k++){
				
				if(j!=k&&sj[j][k]<(1<<30)) dp[i][j]=min(dp[i][j],dp[i-1][k]+sj[j][k]);
				
			}
		}
	}
	
	for(auto hx:a[y]){
		ans=min(ans,dp[m-1][hx]+t[hx][y]+w[y]);
	}
	
	printf("%d\n",ans);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&zbh,&ddd);
			a[zbh].push_back(i); 
			t[i][zbh]=ddd;
		}
	}
	
	memset(sj,127,sizeof(sj));
	for(int i=1;i<=n;i++){
		for(auto hx:a[i]){
			for(auto kkx:a[i]){
				if(hx!=kkx) {
					sj[hx][kkx]=min(sj[hx][kkx],t[hx][i]+t[kkx][i]);
					sj[kkx][hx]=sj[hx][kkx];
				}
			}
		}
	}
	
	for(int i=1;i<=q;i++) solve();
	
	return 0;
} 
