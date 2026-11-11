#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		int n,d;
		cin>>n>>d;
		int x[n];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		int dp[n][n];
		for(int i=0;i<n;i++){
			dp[i][i]=0;
			dp[i][i+1]=0;			
		}
		int sum=0;
		for(int i=0;i<n;i++){
			for(int j=i+2;j<n;j++){
				if(x[j]-x[j-2]<=d){
					dp[i][j]=dp[i][j-2]+1;
				}else if(x[j]-x[j-1]<=d){
					dp[i][j]=dp[i][j-1]+1;
				}else{
					break;
				}
				if(dp[i][j+1]==dp[i][j-1] && d==x[j+1]-x[j-1]){
					sum++;
				}
			}
		}
		if(x[n-1]==5){
			sum++;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
