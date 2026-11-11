#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in.in","r",stdin);
	freopen("string.out.out","w",stdout);
	long long n,a,b=0,c=0;
	char z2;
	string z;
	cin>>n;
	
	for(long long i=0;i<n;i++){
		cin>>a>>z2;
		b=b+a;
		for(long long j=0;j<n;j++){
			z=z+z2;
		}
	}
	if(n/2==0){
		n=n+1;
	}
	for(long long i=0;i<n/2;i++){
		if(z[i]!=z[b-i]){
			c=c+1;
		}
	}
	cout<<c;
	return 0;
}
