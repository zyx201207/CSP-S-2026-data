#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,x=0,s=0,d;
	int k[10001];
	char w;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>w;
		x+=k[i];
		for(int j=1;j<=k[i];j++){
			a+=w;
		}
	}
	x=x/2;
	for(int i=0;i<x;i++){
		d=n-i;
		if(a[i]-'0'!=a[d]-'0'){
			s+=1;
		}
	}
	cout<<s;
}

