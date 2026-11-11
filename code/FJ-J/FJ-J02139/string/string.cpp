#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	char b[n];
	string c;
	long long sum=0;
	long long s=0;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=0;i<n;i++){
		for(long long k=0;k<a[i];k++){
			c[sum]=b[i];
			sum++;
		}
	}
	for(long long i=0;i<sum;i++){
		if(c[sum-1]!=c[i]){
			s++;
		}
		sum--;
		}
		cout<<s;
	return 0;
}
