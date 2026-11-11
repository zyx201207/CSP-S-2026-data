#include <bits/c++.h>
using namespace std;
int main(){

	freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	long long n,a[100009],c[100009],b=0,d=0;
	for(int i=0;i<n;i++){
		cout<<a[i]<<c[i];
		b+=a[i];
	}
	for(int i=0;i<b/2;i++){
		if(a[i]!=a[b-i-1])
		d++;
	}	
	cout<<d;
return 0;}
