#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500010];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<m;i++){
		long long b=a[0];
		long long c;
		for(long long j=0;j<n;j++){
			if(b>=a[j]){
			    b=a[j];
			    c=j;
	      	}
		}
		a[c]=a[c]+1;
	}
	long long b1=a[0],c1;
	for(long long i=0;i<n;i++){
		if(b1>=a[i]){
			b1=a[i];
			c1=i;
		}
	}
	long long d=0;
	for(long long i=0;i<n;i++){
		if(a[i]==a[c1]){
			d++;
		}
	} 
	cout<<d;
	return 0;
} 
