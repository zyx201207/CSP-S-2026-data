#include<bits/stdc++.h>
using namespace std;
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	while(n--){
		long long a;
		string b;
		cin>>a>>b;
		for(long long i=1;i<=a;i++){
			s+=b;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


