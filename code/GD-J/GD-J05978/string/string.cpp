#include<bits/stdc++.h>
using namespace std;
long long a,n,s=0,l=0;
string c;
char b;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		cin>>b;
		for(int j=l;j<a+l;j++){
			c[j]=b;
		}
		l=l+a;
	}
	for(int i=0;i<l/2;i++){
		if(c[i]!=c[l-i])s++;
	}
	cout<<s-1;
	return 0;
} 
