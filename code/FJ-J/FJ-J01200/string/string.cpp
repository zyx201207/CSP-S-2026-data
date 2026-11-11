#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long h;
		char aas;
		cin>>h>>aas;
		for(long long k=1;k<=h;k++){
			s=s+aas;
		}
	}
	long long l=0,r=s.size()-1,as=0;
	while(l<r){
		if(s[l]!=s[r]){
			as++;
		}
		l++;
		r--;
	}
	cout<<as;
	return 0;
}
