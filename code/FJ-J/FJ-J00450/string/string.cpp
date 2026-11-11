#include<bits/stdc++.h>
using namespace std ;
string s,s1,s2 ;
long long dp[9999][9999];
long long check(string s1,string s2){
	long long len=s1.size() ;
	s1=" "+s1;s2=" "+s2 ;
	for(long long i=1;i<=len;i++){
		for(long long j=1;j<=len;j++){
			if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1] ;
			else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1 ;
			}
		}
	}
	return dp[len][len] ;
}
int main(){
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	int n ;
	cin >>n ;
	for(int i=1;i<=n;i++){
		int x ;
		char c ;
		cin >> x >> c ;
		for(int j=1;j<=x;j++){
			s=s+c ;
		} 
	}
	if(n<=1){
		cout << 0 ;
		return 0 ;
	}
	s1=s+s ;
	s2=s ;
	for(int i=s.size()-1;i>=0;i--){
		s2=s2+s[i] ;
	}
	
	long long x=check(s1,s2) ;
	if(x%3==0)cout<< x/3 ;
	else cout << x/3+1 ;
	return 0 ;
}

