#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	for(int i=1;i<=T;i++){
		int n,d;
		cin>>n>>d;
		int x[10005];
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		int dp[10005]={};
		int min=1e9+1
		for(int i=1;i<=n-3;i++){
			int sum=0;
			
			for(int j=i+2;j<=n;j++){
			
				for(int k=j-1;k>=i;k++){
					if(x[j]-x[k]<=d){
						if(dp[k]<min){
							min=dp[k];
						}else if(dp[k]==min){
							sum++;
							break;
						}
					}
				}
				dp[j]=min;
			}
		}
		if(min>=1e9+1){
			cout<<0;
		}else{
		cout<<min<<endl;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
