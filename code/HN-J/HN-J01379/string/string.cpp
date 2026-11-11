#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long m=0;
	char a[100005],b[100005],c[100005];
	long f=0;
	for(long long i=0;i<n;i++){
		long x;
		cin>>x;
		char d;
		cin>>d;
		
		for(long long j=0;j<x;j++){
			a[j+f]=d;
			m++;
		}f+=x;
	}
	for(long long i=0;i<(m-1)/2;i++){
		b[i]=a[i];
	}
	long long j=0;
	for(long long i=m-1;i>(m-1)/2;i--){		
		c[j]=a[i];
		j++;
	}
	long long u=0;
	for(long long i=0;i<(m-1)/2;i++){
		if(b[i]!=c[i]){
			u++;
		}
	}
	cout<<u;
	return 0;
} 
