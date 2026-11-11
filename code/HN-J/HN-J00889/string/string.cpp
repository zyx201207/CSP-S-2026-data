#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string a;
	while(n--){
		long long x;  
		char y;
		cin>>x>>y;
		for(long long i=1;i<=x;i++){
			a+=y;
		}
	}
	long long cnt=0,l=0,r=a.size()-1;
	while(l<=r){
		if(a[l]!=a[r]){
			cnt++;
		}
		l++;r--;
	}
	cout<<cnt;
	return 0;
}  

