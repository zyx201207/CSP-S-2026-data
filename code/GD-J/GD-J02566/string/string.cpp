#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],ct=0;char c[N];
vector<char> l;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1];m=a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)l.push_back(c[i]); 
	}
	long long mun=l.size();
	for(long long i=0;i<mun/2;i++){
		if(l[i]!=l[mun-i-1])ct++;
	}
	cout<<ct;
	return 0; 
}

