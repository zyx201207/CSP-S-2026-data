#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<char> a;
	long long cnt=0;
	for(long long i=0;i<n;i++){
		long long x;
		char b;
		cin>>x;
		cin>>b;
		for(long long j=0;j<x;j++){
			a.push_back(b);
		}
	}
	long long r=a.size()-1;
	long long mid=r/2;
	for(long long i=0;i<=r;i++){
		if(a[i]!=a[r]){
			a[r]=a[i];
			r--;
			cnt++;
		}else{
			r--;
		}
}
		cout<<cnt;
	
	return 0;
}
