/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>*/
#include<bits/stdc++.h>
int const MAX=10000005;
int a[MAX];
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,s;
	string y="";
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	return 0;
}
