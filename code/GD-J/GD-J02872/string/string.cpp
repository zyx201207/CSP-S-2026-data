#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",std);
	freopen("string.out","w",std);
	int a,e=0,f=0;
	int b[2000]={};
	char c[2000]={};
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
		if(b[i]>b[i+1]){
			b[i]=e;
			b[i]=b[i+1];
			b[i+1]=e;
		}
		
		cin>>c[i];
	
	}
	for(int i=0;i<a-1;i++){
		f += b[i];
	}
	
	cout<<f;
	return 0;	
} 
