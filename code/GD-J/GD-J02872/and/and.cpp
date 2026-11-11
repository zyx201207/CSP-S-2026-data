#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",std);
	freopen("and.out","w",std);
	int a,b;
	int c[2000]={};
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	cout<<c[a-1];
	return 0;	
} 
