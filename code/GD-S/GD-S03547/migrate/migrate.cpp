#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,mp[2001000];
int main(){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>mp[i];
		}
		long long dp[2001000][2001000],sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) dp[i][j]=0;
				else if(i>j) dp[i][j]=0;
				else if(i<j&&mp[j]-mp[i]<=d) dp[i][j]=1;
				else if(i<j&&mp[j]-mp[i]>d&&mp[j]-mp[i]<d*d){
					dp[i][j]=2;
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
