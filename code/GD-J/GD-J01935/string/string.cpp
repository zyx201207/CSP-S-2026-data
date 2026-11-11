#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,a,b;
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		string t;
		cin>>x>>t;
		for(long long j=1;j<=x;j++){
			s+=t;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		a+=s[i];
	}
	for(long long i=s.size()-1;i>s.size()/2;i--){
		b+=s[i];
	}
	for(long long i=0;i<s.size()/2;i++){
		if(a[i]!=b[i])ans++;
	}
	cout<<ans;
	return 0;
} 
