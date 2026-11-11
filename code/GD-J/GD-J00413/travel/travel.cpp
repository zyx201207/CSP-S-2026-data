#include<bits/stdc++.h>
using namespace std;
string rc,xc;
string rs,xs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>rc>>rs>>xc>>xs;
	bool p=0;
	for(int i=0;i<=1;i++)
	{
		if(rc[i]!=xc[i])
		{
			p=1;
			break;
		}
	}
	if(p==0)
	{
		cout<<'1';
		bool fl=0;
		for(int i=0;i<2;i++)
		{
			if(rs[i]!=xs[i])
			{
				fl=1;
				break;
			}
		}
		if(fl==1)
		{
			cout<<"000";
		}else
		{
			cout<<'1';
			bool f1=0,f2=0;
			if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')
			{
				f1=1;
			}if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')
			{
				f2=1;
			}
			if(f1==f2)
			{
				cout<<'1';
				if(f1==0)
				{
					cout<<'1';
				}else
				{
					if((rs[2]=='A'&&xs[2]=='C')||(rs[2]=='C'&&xs[2]=='A'))
					{
						cout<<'0';
					}else
					{
						cout<<'1';
					}
				}
			}else
			{
				cout<<"00";
			}
			
		}
	}else
	{
		cout<<"0000";
	}
	
	return 0;
} 
