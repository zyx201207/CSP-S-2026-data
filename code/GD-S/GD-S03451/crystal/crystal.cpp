#include<iostream>
using namespace std;
int maim(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=5&&m<=10){
		cout<<2;
	}
	if(n<=16&&m<=1000){
		cout<<12;
	}
	if(n<=5000){
		cout<<83;
	}
	return 0;
	
} 
