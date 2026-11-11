#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int chexiang;
	string zuowei;
	int chexiang2;
	string zuowei2;
	cin>>chexiang>>zuowei>>chexiang2>>zuowei2;
	int a=0,b=0,c=0,d=0;
	string sit="",sit2="",ch="",ch2="";
	for(int i=1;i<=3;i++)
	{
		if(i==3)
		{
			ch+=zuowei[i-1];
			ch2+=zuowei2[i-1];
		}
		else
		{
			sit+=zuowei[i-1];
			sit2+=zuowei2[i-1];
		}
	}
//	cout<<chexiang<<" "<<chexiang2<<" "<<ch<<" "<<ch2<<sit<<" "<<sit2;
	if(chexiang==chexiang2)
	{
		a=1;
		if(sit==sit2)
		{
			b=1;
			if(ch=="A"||ch=="B"||ch=="C")
			{
				if(ch2=="A"||ch2=="B"||ch2=="C")
				{
					c=1;
					if((ch=="A"&&ch2=="B") ||(ch=="B"&&ch2=="C")||(ch=="B"&&ch2=="A")||(ch=="C"&&ch2=="B"))
					{
						d=1;
					}
				}
				else
				{
					c=0;
				}
			}
			else
			{
				if(ch2=="D"||ch2=="F")
				{
					c=1;d=1;
				}
				else
				{
					c=0;d=0;
				}
			}
		}
		else
		{
			b=0;
		}
	}
	else
	{
		a=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
