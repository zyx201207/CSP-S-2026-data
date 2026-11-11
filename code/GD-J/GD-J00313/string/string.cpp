#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n=0,s=0,q=0,m=0;cin>>n;long long l=0,r=n-1;
	long long a[n];char c[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		q+=a[i];
	}string p[q];
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			p[m]=c[i];
			m++;
		}
	}
	for(long long i=0;i<=q/2;i++){
		if(p[i]!=p[q-1-i]){
			s++;
			p[q-1-i]=p[i];
		}
	}
	cout<<s;
	return 0;
}
