#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s="";
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long num;
		char a;
		cin>>num>>a;
		for(long long j=1;j<=num;j++){
			s+=a;
		}
	}
	string s_r="";
	for(long long i=s.size()-1;i>=0;i--){
		s_r+=s[i];
	} 
	if(s_r==s){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s_r[i]!=s[i])ans++;
	}
	cout<<ans;
	return 0;}

