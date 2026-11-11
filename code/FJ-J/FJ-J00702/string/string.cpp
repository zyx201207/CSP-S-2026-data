#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	long long b[a+1];
	char c[a+1];
	for(long long i=1;i<=a;i++){
		cin>>b[i]>>c[i];
	}
	string x,s;
	for(long long i=1;i<=a;i++){
		for(int j=1;j<=b[i];j++){
			x+=c[i];
		}
	}
	for(long long i=a;i>=1;i--){
		for(int j=1;j<=b[i];j++){
			s+=c[i];
		}
	}
	long long z=0;
	for(long long i=1;i<=a;i++){
		z+=b[i];
	}
	z=floor(z/2);
	long long m=0;
	for(long long i=0;i<z;i++){
		if(x[i]!=s[i]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
