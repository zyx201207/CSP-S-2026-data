#include<bits/stdc++.h>
using namespace std;
string a[1000000]={};
string a1[1000000]={};
int b[1000000]={};
string c[1000000]={};
int main(){
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
		for(int j=x;j<x+b[i];j++){
			a[j]=c[i];
		}
		x+=b[i];
	}
	int t=0;
	for(int i=x-1;i>=0;i--){
		a1[t]=a[i];
		t++;
	}
	int g=t/2,h=0;
	for(int i=0;i<=g;i++){
		if(a[i]!=a1[i]) h++;
	}
	cout<<h;
}	
