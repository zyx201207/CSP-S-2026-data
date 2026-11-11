#include<bits/stdc++.h>
using namespace std;
char sr[1011],sx[1011];
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	cin>>cr>>sr>>cx>>sx;
	char ar=sr[2],ax=sx[2];
	int br=sr[0],bx=sx[0],dr=sr[1],dx=sx[1];
	if(ax>ar)
	{
		swap(ar,ax);
	}
	if(cr==cx)
	{
		cout<<1;
		if(br==bx&&dr==dx)
		{
			cout<<1;
			if((ar<=67&&ax<=67)||(ar>67&&ax>67))
			{
				cout<<1;
				if(ar-ax==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
