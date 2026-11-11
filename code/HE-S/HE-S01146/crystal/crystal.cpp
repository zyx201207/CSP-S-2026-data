#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[500009],v[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	v[0]=a[0];
	for(int i=1;i<n;i++){
		v[i]=v[i-1]+a[i];
	}
	for(int i=1;i<n;i++){
		long long sum=a[i]*i-v[i-1];
		if(sum>m){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
