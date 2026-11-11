#include<bits/stdc++.h>
using namespace std;
const int N=2e4+2;
int dp[N][N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char>v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int l;
		char c;
		cin>>l>>c;
		while(l--)v.push_back(c);
	}
	n=v.size();
	for(int len=2;len<=n;len++){
		for(int l=0;(l+len-1)<n;l++){
			int r=l+len-1;
			if(v[l]==v[r]){
				dp[l][r]=dp[r+1][l-1];
			}else{
				dp[l][r]=min({dp[l+1][r],dp[l][r-1],dp[l+1][r-1]})+1;
			}
		}
		
	}
	cout<<dp[0][n-1];
	return 0;
}
