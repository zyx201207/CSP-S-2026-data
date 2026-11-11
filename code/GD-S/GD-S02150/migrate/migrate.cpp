#include<bits/stdc++.h>
using namespace std;

int c,t;


void work(){
	int n,d; cin>>n>>d;
	int x[n+1];
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c==11 || c==12){
		int xd=d/(x[2]-x[1]); //最多一次性跨过几个
		int dp[n],ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=xd && i+j<=n;j++){
				dp[i+j]++;
			}
		} 
		for(int i=1;i<=n;i++){
			if(dp[i]==2) ans++;
			cout<<dp[i]<<' ';
		}
		cout<<ans;
	}
}

int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
} 
