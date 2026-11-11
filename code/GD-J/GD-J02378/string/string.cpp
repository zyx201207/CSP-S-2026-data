#include <bits/stdc++.h>
using namespace std;
int n;
string a;
int cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cnt+=k;
		string b;
		cin>>b;
		for(int j=1;j<=k;j++){
			a+=b;
		}
	}
	
	string c,d;
	int f=(cnt+1)/2;
	
	for(int i=f;i>=0;i--){
		c+=a[i];
	}
	for(int j=f;j<a.size();j++){
		d+=a[j];
	}
	
	int dp[1009][1009];
	
	for(int i=1;i<=f;i++){
		for(int j=1;j<=f;j++){
			if(c[i]==d[i]){
				dp[i][j]=dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j]+1,dp[i][j-1]+1));
			}
		}
	}
	cout<<dp[f][f];
	return 0;
}
