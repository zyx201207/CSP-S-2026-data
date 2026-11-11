#include<bits/stdc++.h>
using namespace std;
long long x[2000006];
long long dp[2000006];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int y=d/(x[n]-x[n-1]);
		for(int i=2;i<=n;i++){
			if(i>d){
				dp[i]=dp[i-1]+(i-1)-(i-1)/d-d+1;
			}
			else dp[i]=dp[i-1];
		}
		cout<<dp[n]<<endl;
		for(int i=1;i<=n;i++){
			x[i]=0;dp[i]=0;
		}
		t--;
	}
}
