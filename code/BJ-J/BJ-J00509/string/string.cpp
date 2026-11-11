#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	string s = "";
	while(n--){
		long long a;
		char b;
		cin>>a>>b;
		for(;a>0;a--) s+=b;
	}
	
	long long ans = 0;
	for(long long i = 0;i+i<s.length();i++){
		if(s[i]!=s[s.length()-i-1]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}