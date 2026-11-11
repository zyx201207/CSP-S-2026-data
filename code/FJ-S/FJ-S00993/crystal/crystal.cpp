#include <bits/stdc++.h>
using namespace std;
//   5 8 -3 -1 2 2 7

struct cr{
	int ans;
	int num;
};

int n,m;
int arr[500005];
cr dp[100][1000];

int main(){
	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	
	for(int i=1;i<=m;i++){
		dp[1][i].ans = 1;
		dp[1][i].num = arr[1];
	}
		
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			for(int l=1;l<=i;l++){
				
				int t = arr[++l]-arr[l];
				dp[i][j] = dp[i-1][j];
				
				if(t<=j){
					if(dp[i-1][j-t].num==arr[l]){
						if(dp[i-1][j-t].ans+1>dp[i][j].ans){
							dp[i][j].ans=dp[i-1][j-t].ans+1;
							dp[i][j].num=arr[l];
						}
					}else dp[i][j].ans=max(dp[i][j].ans,1);
				}
				
			}
			
			printf("%d",dp[i][j]);
		}
		printf("\n");
	}
	
	
	cout << dp[n][m].ans;
	
	return 0;
}
