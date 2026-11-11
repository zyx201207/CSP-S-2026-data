#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
int main(){
	int x;
	cin>>x;
	long long m[1000000005]={};
	char n[200005]={};
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin<<a<<b;
		for(int j=0;j<a;j++){
			m[i]=a;
			n[i]=b;
		}
	}
	return 0;
}

