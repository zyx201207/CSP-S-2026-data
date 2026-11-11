#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0;
	cin>>n;
	long long a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		x+=a[i];
	}
	char s[x];
	long long c=0;
	for(int i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s[c]=b[i];
			c++;
		}
	}
	long long g=0;
	for(long long i=0;i<x/2;i++){
		if(s[i]!=s[x-i-1]){
			g++;
		}
	}
	cout<<g;
	return 0;
}


