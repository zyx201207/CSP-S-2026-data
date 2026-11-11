#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long all=0;
	cin>>n;
	long long q;
	char p;
	for(long long i=0;i<n;i++){
		cin>>q>>p;
		for(long long j=0;j<q;j++){
			a+=p;
		}
	} 
	long long b=a.size();
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[b-i-1]){
			all++;
		}
	}
	cout<<all;
	return 0;	
} 

