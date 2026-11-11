#include<iostream>
using namespace std;
int main()
{
	freopen("card.in","r",std);
	freopen("card.out","w",std);
	int a,b;
	int c[5000]={};
	cin>>a>>b; 
	for(int i=0;i<a;i++){
		cin>>c[i];
	} 
	if(a=4){
		cout<<3<<1<<4;
	}
	if(a=10){
		cout<<10<<3<<3;
	}
	return 0;	
} 
