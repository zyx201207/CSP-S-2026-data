#include<iostream>
using namespace std;
int main()
{
	freopen("r""travel.in");
	freopen("w""travel.out");
	
	char a[17][4],b[17][4];
	for(int i=0;i<17;i++)
	{
		cin>>a[17];
		for(int j=0:j<4;j++)
		{
			cin>>a[4];
		}
	}
	for(int i=0;i<17;i++)
	{
		cin>>b[17];
		for(int j=0;j<4;j++)
		{
			cin>>b[4];
		}
	}
	if(a[17]==b[17])
	{
		cout<<"1";
			if(a[4]==b[4])
			{
				cout<<"1";
			}
			else
			cout<<"0";
	}
	else
	cout<<"0";
	return 0;
}
