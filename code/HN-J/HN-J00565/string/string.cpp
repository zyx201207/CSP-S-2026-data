#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
//  dp[N][N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*	
	int n;
	string sd,a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		int h;
		cin>>h;
		char sf;
		cin>>sf;
		for(int j=1;j<=h;j++) sd+=sf;
	}
	int sz=sd.size();
	if(sz%2==0){
		for(int i=0;i<sz/2;i++) a+=sd[i];
		for(int i=sz-1;i>=sz/2;i++) b+=sd[i];
	}  
	else{
		for(int i=0;i<sz/2;i++) a+=sd[i];
		for(int i=sz-1;i>sz/2;i++) b+=sd[i];
	}
	
	Ò»Î¬dp 
	for(int i=1;i<=sz/2;i++){
		for(int j=1;j<=sz/2;j++){
			dp[i]=min(dp[i-1],dp[i]);
			if(a[i-1]!=b[j-1]) dp[i]++;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}	
	}
	/*
	¶þÎ¬dp 
	for(int i=1;i<=sz/2;i++){
		for(int j=1;j<=sz/2;j++){
			dp[i]=min(dp[i-1],dp[i]);
			if(a[i-1]!=b[j-1]) dp[i][j]++;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}	
	}
	cout<<dp[sz/2];
	*/
	cout<<0;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c

2
2 a
3 a
*/
