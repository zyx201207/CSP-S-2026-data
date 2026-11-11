#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[1000000000005],s[1000000000005];

int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	s[0]=a[0];
	for(long long i=0;i<n;i++){
		s[i]=s[i-1]+a[i];
	}
	sort(a,a+n);
	long long mx=0;
	for(long long i=0;i<n;i++){
		if(a[i]*i-s[i]<=m){
			mx=i+1;
		}
	}
	cout<<mx;
	return 0;
}
