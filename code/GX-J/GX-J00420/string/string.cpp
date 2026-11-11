#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	long long n,a,x,o=0;
	char b;
	cin>>n;
	string s="";
	for (long long i=0;i<n;i++){
		cin>>a;
		cin>>b;
		for (long long j=0;j<a;j++)
			s=s+b;
	}
	x=s.size();
	for (long long i=0;i<=x/2;i++){
		if (s[i]!=s[x-i-1]){
			o++;
		}
	}
	
	cout<<o;
	return 0;
}
