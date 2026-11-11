#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long n1;
		string s1;
		cin>>n1>>s1;
		while(n1--){
			s+=s1;
		}
	}
	for(long long i=0;i<(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
