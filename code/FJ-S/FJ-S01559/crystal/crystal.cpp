#include<bits/stdc++.h>
using namespace std;
long long a[1919810];
long long s[1919810];
int main(){
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(long long i=n;i>=1;i--){
		if(a[i]*i-s[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
