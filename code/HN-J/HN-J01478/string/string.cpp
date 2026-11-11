#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[100001],sb,dsb=1;
	long long e=0;
	char b[100001]; 
	cin>>sb;
	for(int i=0;i<sb;i++){
		cin>>a[i]>>b[i];
		e+=a[i];
	} 
	for(int i=0;i<sb-1;i++){
		if(b[i]!=b[i+1]) dsb=0;
	}
	if(dsb=1){
		cout<<"0";
		return 0;
	}
	cout<<e/2;
	return 0;
} 
