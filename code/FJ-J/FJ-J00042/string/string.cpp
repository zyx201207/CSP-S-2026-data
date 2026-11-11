#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=0;j<a;j++){
			s+=b;
		}
	}
	long long len_s=s.size();
	long long cnt=0;
	for(long long i=0;i<len_s/2;i++){
		if(s[i]!=s[len_s-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
} 
