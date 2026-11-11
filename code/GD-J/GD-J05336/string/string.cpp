#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ai,cnt=0;
	char ci;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		cin>>ai>>ci;
		for(long long j=1;j<=ai;j++){
			s+=ci;
		}
	}
	long long l=s.size();
	long long l1=l/2;
	for(long long i=0;i<l1;i++){
		long long j=l-1;
		j-=i;
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
} 
