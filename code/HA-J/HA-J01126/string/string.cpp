#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,ct=0;
long long a[1000001];
char c[1000001];	
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[x]=c[j];
			x++;
		}
	}
	int l=1;
	int r=s.length();
	while(l!=r){
		if(s[l]!=s[r]){
			ct++;
		}
		l++;
		r--;
	}
	cout<<ct;
	return 0;
}
