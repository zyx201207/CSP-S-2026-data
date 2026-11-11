#include<bits/stdc++.h>
using namespace std;

long long f(long long a[],long long k,long long i,long long n,long long m){
	if(m==0) return k;
	for(int j=i+1;j<n;j++){
		k=k&a[j];
		k=max(k,f(a,k,j,n,m-1));
	}
	return k;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m,sum=0;
	long long a[INT_MAX];
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];	
	
	for(long long i=0;i<n;i++) sum=max(sum,f(a,a[i],i,n,m-1));
	
	cout<<sum;
	return 0;
	
}
