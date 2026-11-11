#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string1.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,e=0,n=0;
	char c,d[8000000];
	cin>>a;
	for(long long i=1;i<=a;i++){
		cin>>b>>c;
		for(int j=1;j<=b;j++){d[j+e]=c;}
		e+=b;
	}
	for(long long i=1;i<=e/2;i++){if(d[i]!=d[e-i+1]){n++;}}
	cout<<n;
	return 0;
}
