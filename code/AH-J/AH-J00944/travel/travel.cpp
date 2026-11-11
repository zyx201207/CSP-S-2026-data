#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[15];
	char b[15];
	for(int i=0;i<10;i++)
	{
		cin>>b[i];
		a[i]=b[i]-'0';
	}
	if(a[0]==a[5]&&a[1]==a[6])
	{
		cout<<'1';
		if(a[2]==a[7]&&a[3]==a[8])
		{
			cout<<'1';
			if((a[4]<'D'-'0'&&a[9]<'D'-'0')||(a[4]>'c'-'0'&&a[9]>'c'-'0'))
			{
				cout<<'1';
				if(a[4]+1==a[9]||a[9]+1==a[4])
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
