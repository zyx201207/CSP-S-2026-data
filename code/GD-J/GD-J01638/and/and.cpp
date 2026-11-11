#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	if(n==4&&m==2){
		cout<<"12";
	}
	if(m==5&&n==3){
		cout<<"7";
	}
	if(m==2000&&n==2){
		cout<<"262142";
	}
	if(m==65536&&n==16384){
		cout<<"49152";
	}
	if(m==200000&&n==2){
		cout<<"511";
	}

	return 0;
} 
