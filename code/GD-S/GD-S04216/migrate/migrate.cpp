#include<bits/stdc++.h>
using namespace std;

int c,T,n;
long long d;
long long x[2000005];
//int dp[2000005][2000005];
int dp[305][305][305];

int main(){
	
//	double st = clock();
	
//	freopen("migrate3.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>c>>T;
	
	for(int t=0;t<T;t++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++){
			dp[i][i][0] = 1;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int l=1;l<=j-i;l++){
					dp[i][j][l] = 0;
					for(int k=i;k<j;k++){
						if(x[j] - x[k] <= d){
							dp[i][j][l] += dp[i][k][l-1];
						}
					}
				}
			}
		}
		
		long long ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool flag = false;
				for(int l=1;l<=j-i;l++){
					if(flag) break;
//					printf("%d (%d,%d,%d)=%d\n",t,i,j,l,dp[i][j][l]);
					if(dp[i][j][l] != 0) flag = true;
					if(dp[i][j][l] == 2){
						ans ++;
					}
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
//	double et = clock();
//	cerr<<"\n"<<et-st<<"ms";
	
	return 0;
} 
