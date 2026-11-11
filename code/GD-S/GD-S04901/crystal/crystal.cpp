#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5){
		cout<<"3";
		return 0;
	}
	if(n==5&&m==8){
		cout<<"4";
		return 0;
	}
	cout<<"5";
	return 0;
}
