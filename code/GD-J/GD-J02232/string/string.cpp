#include<bits/stdc++.h>
using namespace std;
long long n,a;
string b;
char s;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	cin>>n;
	long long len=0;
	for(long long i=0;i<n;i++){
		cin>>a>>s;
		for(long long l=0;l<a;l++)b+=s;
		len+=a;
	}
	long long k=0;
	for(long long i=0;i<=len/2-1;i++){
		if(b[i]!=b[len-i-1])k++;
	}
	cout<<k;
	return 0;
}
