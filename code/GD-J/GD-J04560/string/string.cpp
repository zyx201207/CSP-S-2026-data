#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int m=0;
	string a;
	string b;
	for(int i=0;i<n;i++){
		int x;
		string z;
		cin>>x>>z;
		m+=x;
		while(x--){
			a+=z;
		}
	}
	for(int i=m-1;i>=0;i--){
		b+=a[i];
	}
	if(a==b){
		cout<<0;
		return 0;
	}
	int dp[505][505]={};
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(a[i]!=b[j]){
			    dp[i][j]=dp[i-1][j-1]+1;
		    }
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[m-1][m-1]/2;
	return 0;
}
