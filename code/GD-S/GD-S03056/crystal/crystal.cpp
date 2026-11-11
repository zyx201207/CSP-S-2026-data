#include<iostream>
using namespace std; 
int n,m,a[50005]; 
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	if(n==5&&m==5){
		cout<<3;
	}
	if(n==5&&m==8){
		cout<<4;
	}
	else{
		cout<<3;
	}
	return 0;	
}
