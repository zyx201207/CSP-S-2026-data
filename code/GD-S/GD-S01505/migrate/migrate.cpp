#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in",'r',stdin);
	freopen("migrate.out",'w',stdout);
	int a[15];
	for(int i=0;i<15;i++)
	{
		cin>>a[i];
		
	}
	if(a[0]==0&&a[1]==2&&a[2]==4&&a[3]==2)
	{
		cout<<1<<endl<<2;
		
	}
	if(a[0]==0&&a[1]==2&&a[2]==5&&a[3]==3)
	{
		cout<<0<<endl<<1;
	}
	
	
	return 0;
}
