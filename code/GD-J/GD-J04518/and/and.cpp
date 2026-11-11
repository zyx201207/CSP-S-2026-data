#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long m;
	cin>>m;
	long long a[200000]={0};
	long long max1=0;

	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			max1=(max1,a[i]&a[j]);
		}
	}
	cout<<max1;

	return 0;
}
