#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[7005][7005];
int n,length;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s=" ";
	for(int i=1;i<=n;i++){
		ll k;
		char ss;
		cin>>k>>ss;
		for(int j=1;j<=k;j++)s+=ss;
		length+=k;
	}
	for(int i=2;i<=length;i++){
		for(int j=1;j<=length-i+1;j++){
			ll i1=j,j1=i+j-1;
			if(s[i1]==s[j1]){
				dp[i1][j1]=dp[i1+1][j1-1];
			}else{
				dp[i1][j1]=dp[i1+1][j1-1]+1;
			}
		}
	}
	cout<<dp[1][length];
	return 0;
}
