#include<bits/stdc++.h>

using namespace std;

int c,t,n,d,dp[10010][10010][2],x[1000010],ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	for(int i=0;i<t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int f=1;f<=n;f++){
			dp[f][f][0]=1;
			dp[f][f][1]=0;
			for(int j=f+1;j<=n;j++){
				dp[f][j][1]=INT_MAX;
				for(int k=f;k<j;k++){
					if(x[j]-x[k]>d) continue;
					int len=dp[f][k][1]+1;
					if(len<dp[f][j][1]){
						dp[f][j][1]=len;
						dp[f][j][0]=1;
					}
					else if(len==dp[f][j][1]){
						dp[f][j][0]++;
					}
				}
			
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
//				cout << dp[j][k][0] << ' ' << dp[j][k][1] << ",";
				if(dp[j][k][0]==2) ans++;
			}
//			cout << endl;
		}
		cout << ans << endl;
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
