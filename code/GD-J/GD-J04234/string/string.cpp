#include<iostream>
using namespace std;
char a[1000000000];
int main()
{
	int n,ai,s=1,x=0,y=0;
	char ci;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai>>ci;
		x+=ai;
		for(int j=1;j<=ai;j++)
		{
			s++;
			a[s]=ci;
		}
	}
	for(int i=1;i<=x/2;i++)
	{
		if(a[i]!=a[x])
		{
			y++;
		}
		x--;
	}
	cout<<y<<endl;
	return 0;
}
