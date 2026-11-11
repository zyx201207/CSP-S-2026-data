#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long long a=100000;
	char s[a],ci[a];
	long long n,ai[a],z=0,mid,js=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>ai[i]>>ci[i];
		for(long long j=1+z;j<=z+ai[i];j++){
			s[j]=ci[i];
		}
		z+=ai[i];
	}
	mid=z/2;
	for(long long i=0;i<=mid;i++){
		if(s[i+1]==s[z-i])continue;
		else {
			s[z-i]=s[i+1];
			js++;
		}
	}
	cout<<js;
	return 0;
}
