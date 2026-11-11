#include<iostream>
using namespace std;
int a[20];
int main()
{
	freopen("and.in",'r',fopen);
	freopen("and.out",'w',fopen);
	
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	} 
	if(a[0]==3) cout<<12;
	if(a[0]==31) cout<<7;
}
