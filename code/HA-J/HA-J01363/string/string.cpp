#include<bits/stdc++.h>
using namespace std;
long long a,b[200005];
long long e=1,f=0;
char c[200005],d[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		d[e]=c[i];
		e+=b[i];
	}
	for(long long i=2;i<=e;i++){
		if(d[i]==0)d[i]=d[i-1];
	}
	for(int i=1;i<=e/2;i++){
		if(d[i]!=d[e-i])f++;
	}
	cout<<f;
	return 0;
}
