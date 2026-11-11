#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
long long sum=0;
int main(){
	freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long x;
		string a;
		cin>>x>>a;
		for(int j=0;j<x;j++){
			s=s+a;
		}
	}
	long long  m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i-1]){
			sum++;
		}
	}
	cout<<sum;
} 
