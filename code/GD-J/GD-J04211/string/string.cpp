#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;
	long long a[20005];
	char c;
	string s="";
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(long long j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long len=s.size(),cnt=0;
	for(long long i=0;i<=len/2-1;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}
