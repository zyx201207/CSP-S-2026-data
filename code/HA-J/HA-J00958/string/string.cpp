#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,a,b;
ll n,dp[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		ll x;
		char c;
		cin>>x>>c;
		for(int j=0;j<x;j++)s+=c;
	}
	if(s.size()%2==0){
		for(int i=0;i<s.size()/2;i++)a+=s[i],b+=s[i+s.size()/2];
	}else{
		for(int i=0;i<s.size()/2;i++)a+=s[i],b+=s[i+s.size()/2+1];
	}
	reverse(b.begin(),b.end());
	for(int i=1;i<=a.size();i++){
		if(a[i-1]==b[i-1])dp[i]=dp[i-1]+1;
		else dp[i]=dp[i-1];
	}
	if(s.size()%2==0)cout<<(s.size()-dp[a.size()]*2)-(a.size()-dp[a.size()]);
	else cout<<(s.size()-dp[a.size()]*2)-1-(a.size()-dp[a.size()]);
	return 0;
}
