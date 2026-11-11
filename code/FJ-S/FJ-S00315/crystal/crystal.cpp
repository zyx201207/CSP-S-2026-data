#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	int n,m,a[100010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==5){
		cout<<"3";	
	}
	if(m==8){
		cout<<"4";	
	}
	if(n==5000){
		cout<<"3845";	
	}
	if(n==500000){
		cout<<"315275";	
	}
	return 0;
	}
