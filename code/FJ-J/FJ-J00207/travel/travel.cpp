#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[4],c3[3],c4[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>c2>>c3>>c4;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c3[i])
		{
			cout<<0<<0<<0<<0;
			return 0;
		}
	}
	if(c2[0]==c4[0])
	{
		if(c2[1]==c4[1])
		{
			if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>'C'&&c4[2]>'C'))
			{
				if(max(int(c2[2]),int(c4[2]))-min(int(c2[2]),int(c4[2]))>1)
				{
					cout<<1<<1<<1<<0;
				}
				else
				{
					cout<<1<<1<<1<<1;
				}
			}
			else
			{
				cout<<1<<1<<0<<0;
			}
		}
		else
		{
			cout<<1<<0<<0<<0;
			return 0;
		}
	}
	else
	{
		cout<<1<<0<<0<<0;
		return 0;
	}

	return 0;
}
