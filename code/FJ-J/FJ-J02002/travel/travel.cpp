#include<bits/stdc++.h>
using namespace std;
char l[6]={'A','B','C','D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((('A'<=b[2]&&b[2]<='C')&&('A'<=d[2]&&d[2]<='C')) || (('D'<=b[2]&&b[2]<='F')&&('D'<=d[2]&&d[2]<='F'))))
	{
		cout<<1;
	}	
	else
	{
		cout<<0;
	}
	bool sl=true;
	if(a==c&&b[0]==d[0]&&b[1]==d[1])
	{
		if( (('A'<=b[2]&&b[2]<='C')&&('A'<=b[2]&&b[2]<='C')) || (('D'<=b[2]&&b[2]<='F')&&('D'<=b[2]&&b[2]<='F')) )
		{
			int j,k;
			for(int i=0;i<6;i++)
			{
				if(l[i]==b[2])
				{
					j=i;
				}
				else if(l[i]==d[2])
				{
					k=i;
				}
			}
			if((j+1==k||k+1==j))
			{
				if(j==2&&k==3)
				{
					sl=!sl;
				}
				if(k==2&&j==3)
				{
					sl=!sl;
				}
			}
			else
			{
				sl=!sl;
			}
			if(sl)
			{
				cout<<1;
			}
		}
	}
	else
	{
		cout<<0;
	}
	if(!sl)
	{
		cout<<0;
	}
	return 0;
}
