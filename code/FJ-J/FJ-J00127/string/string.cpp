#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdio);
	freopen("string.out","w",stdio);
	long long n;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		long long h;
		char c;
		cin>>h>>c;
        for(long long j=1;j<=h;j++){
        	s=s+c;
		}
	}	
	s='|'+s;
	long long h=s.size()-1,sum=0;
	for(long long i=1;i<=(h+1)/2;i++){
		if(s[i]!=s[h-i+1]){
			sum++;
		} 
	}
	cout<<sum;
	return 0;
} 
