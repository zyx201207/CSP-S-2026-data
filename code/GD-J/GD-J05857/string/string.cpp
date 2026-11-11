#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[1000005],c[1000005],d[1000005],e[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,x=0;
	
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			c[t]=b[i];
			t++;
		}
	}
	for(long long i=0;i<t/2;i++){
		if(c[i]!=c[t-i-1]) x++;
	}
	cout<<x;
}
