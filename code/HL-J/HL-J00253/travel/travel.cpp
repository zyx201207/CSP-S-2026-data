#include<bits/stdc++.h>
using namespace std;

string ca,sa,cb,sb;
int f(string x)
{
	return (x[0]-48)*10+x[1]-48;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(f(ca)!=f(cb))
	{
		cout<<"0000";
	}
		
	else
	{
		if(f(sa)!=f(sb))
			cout<<1000;
		else
		{
			if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C')
			{
				if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C')
				{
					if(abs(int(sb[2])-int(sa[2]))==1)
						cout<<1111;
					else
						cout<<1110;
				}
				else
					cout<<1100;
			}
			else
			{
				if(sb[2]=='D'||sb[2]=='F')
					cout<<1111;
				else
					cout<<1100;		
			}
		}
	}
}
