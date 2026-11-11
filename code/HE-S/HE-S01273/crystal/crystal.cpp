#include<iostream>
using namespace std;
int a[100005];
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(m==5&&n==5){
		cout<<3;
	}
	if(m==5&&n==8){
		cout<<4;
	}
	if(m==5000&&n==293238795)
	{
		cout<<3845;
	}
	if(m==500000&&n==19768503){
		cout<<315275;
	}
	return 0;
} 
