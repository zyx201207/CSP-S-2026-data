#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	string a;
	for(int i=0;i<n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(long long j=0;j<x;j++){
			a+=c;
		}
	}
	for(long long i=0,j=a.size()-1;i<j;i++,j--){
		if(a[i]!=a[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0; 
} 
