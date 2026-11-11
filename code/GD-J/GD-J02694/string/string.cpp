#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,shuliang=0;cin>>n;
	string s="";
	for(long long i=0;i<n;i++){
		string c="";
		long long a;cin>>a;
		cin>>c;
		for(long long l=0;l<a;l++){
			s+=c;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			shuliang++;	
		}
	}
	cout<<shuliang;
	return 0;
} 
