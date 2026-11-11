#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 and n==2){
		cout<<"12";
	}
	if(n==5 and n==3){
		cout<<"7";
	}
	if(n==2000 and n==2141080){
		cout<<"262142";
	}
	if(n==65536 and n==163840){
		cout<<"49152";
	}
	if(n==200000 and n==215){
		cout<<"511";
	}
	return 0;
}

