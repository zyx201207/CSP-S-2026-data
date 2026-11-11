#include <bits/stdc++.h>
using namespace std; 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long l=0,t=1,sum=0,a;
	cin>>n;
	long long s[10000000]={};
	for(long long i=1;i<=n;i++){
		char c;
		cin>>a>>c;
		l+=a;
		for(long long j=t;j<=t+a;j++){
			s[j]=int(c);
			t++;
		}
	}
	long long f=l/2;
	for(long long i=1;i<=l;i++){
		if(s[i] != s[l-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
