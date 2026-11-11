//GZ-J00510 金浩 兴义市弘毅中学 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,cnt;
string s;
//vector <ll > dp(5005,(vector <ll>(5005,0)));
char c;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
 ios::sync_with_stdio(false);	
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		string d(a,c);
		s=s+d;
		//cout<<1111;
	}
	ll x=s.size();

		for(ll i=x/2-1;(x-1)-i<x;i--){
			if(s[i]!=s[(x-1)-i]) cnt++;
		}
	
	
	cout<<cnt;
//	for(int i=0;i+1<=s.size()-1;i++){
	//	if(s[i]!=s[i+1]){
	//		dp[i][i+1]=1;
	//	}
//	}
//	cout<<s.size();
	//for(int i=s.size()-1;i>=0;i--){
	//	for(int j=i+1;j<s.size();j++){
	//			dp[i][j]=(dp[1+i][j-1]+1);
	//	/	if(s[i]==s[j]) {
	//			dp[i][j]=min(dp[i][j],dp[1+i][j-1]);
	//		}
		//	cout<<dp[i][j]<<" ";
	//	} 
	//	cout<<"\n"; 
//	}
	//cout<<dp[0][s.size()-1];
	return 0;
} 
