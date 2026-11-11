#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001],num[10001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		char c;
		cin>>num[i]>>c;
		for(int j=1;j<=num[i];j++){
			s+=c;
		}
	}
	string t;
	long long ans=0;
	for(int i=s.size()-1;i>=0;i--){
		t+=s[i];
	}
	n=s.size();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<n-dp[n][n];
}
