#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	string s,k;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=0;j<a;j++) s+=b;
	}
	for(long long i=0;i<s.size();i++){
		k = k+s[s.size()-i-1];
	}
	for(long long i=0;i<s.size()/2;i++){
		if(k[i]!=s[i]) sum++;
	}
		
	cout<<sum;
	return 0;
} 
