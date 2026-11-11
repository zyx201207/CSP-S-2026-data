#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long x,n,p=0;
	char c;
	string s="";
	cin >> n;
	for (long long i=0;i<n;i++){
		cin >> x >> c;
		for (long long j=0;j<x;j++){
			s+=c;
		}
		p+=x;
	}
	long long a,b;
	if(p%2==0){
		b=p/2;
		a=b-1;
	}
	else{
		b=p/2;
		a=b;
	}
	long long o=0;
	for(long l=0,r=p-1;l<=a&&r>=b;l++,r--){
		if(s[r]!=s[l]){
			o++;
		}
	}
	cout << o;
	return 0;
}
