#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m,n=0,cnt=0;
	string s;
	cin>>m;
	for(long long i=1;i<=m;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
		}
		n+=a;
	}
	for(long long i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}

