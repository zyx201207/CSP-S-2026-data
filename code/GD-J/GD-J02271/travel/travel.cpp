#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		string a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a == c)
		{
			cout<<1;
			int q = (b[0] - '0') * 10 + (b[1] - '0');
			int p = (d[0] - '0') * 10 + (d[1] - '0');
			if(q == p)
			{
				cout<<1;
				if(b[2] == 'A')
				{
					if(d[2] == 'B' || d[2] == 'C')
					{
						cout<<1;
						if(d[2] == 'B')
						{
							cout<<1<<endl;
							return 0;
						}
						else
						{
							cout<<0<<endl;
							return 0;
						}
					}
					else
					{
						cout<<0<<0<<endl;
						return 0;
					}
				}
				if(b[2] == 'B')
				{
					if(d[2] =='A' || d[2] == 'C')
					{
						cout<<1<<1<<endl;
						return 0;
					}
					else
					{
						cout<<0<<0<<endl;
						return 0;
					}
				}
				if(b[2] == 'C')
				{
					if(d[2] == 'B' ||d[2] == 'A')
					{
						cout<<1;
						if(d[2] == 'B')
						{
							cout<<1<<endl;
							return 0;
						}
						else
						{
							cout<<0<<endl;
							return 0;
						}
					}
					else
					{
						cout<<0<<0<<endl;
						return 0; 
					}
				}
				if(b[2] == 'D')
				{
					if(d[2] == 'F')
					{
						cout<<1<<1<<endl;
						return 0;
					}
					else
					{
						cout<<0<<0<<endl;
						return 0;
					}
				}
				if(b[2] == 'F')
				{
					if(d[2] == 'D')
					{
						cout<<1<<1<<endl;
					}
					else
					{
						cout<<0<<0<<endl;
						return 0;
					}
				}
			}
			else
			{
				cout<<0<<0<<0<<endl;
				return 0;
			}
		}
		else
		{
			cout<<0<<0<<0<<0<<endl;
			return 0;
		}
		return 0;
}
