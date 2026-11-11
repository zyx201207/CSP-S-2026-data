#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	getchar();
	string a="";
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b;
		getchar();
		cin>>c;
		for(int j=1;j<=b;j++){
			a=a+c;
		}
	}
	long long ct=0;
	long long m=a.size();
	for(long long i=0;i<m/2;i++){
		if(a[i]!=a[m-i-1]) ct++;
	}
	cout<<ct;
	return 0;
}

