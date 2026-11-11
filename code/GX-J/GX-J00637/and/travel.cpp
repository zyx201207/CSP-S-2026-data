#include<iostream>
#include<cmath>
using namespace std;
char a[4];
int b[4];
int main()
{
	
	for(int i=1;i<=4;i++)
	{
		cin>>a[i];
	}
	if(a[1]==a[3]) cout<<1000;
	else cout<<0000;
}
