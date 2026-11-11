#include<bits/stdc++.h>
using namespace std;
string s="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int x1,x2,y1,y2;
	char x,y;
	cin>>x1>>y1>>x>>x2>>y2>>y;
	if (x1!=x2) s="0000";
	else
	{
		s+='1';
		if (y1!=y2) s=s+"000";
		else
		{
			s+='1';
			if (x=='A'||x=='B'||x=='C')
			{
				if (y=='D'||y=='E') s=s+"00";
				else
				{
					s=s+"1";
					if (x=='A'&&y=='B') s=s+"1";
					else if (x=='B'&&(y=='A'||y=='C')) s=s+"1";
					else if (x=='C'&&y=='B') s=s+"1";
					else s=s+"0";
				}
			}
			else
			{
				if (y=='A'||y=='B'||y=='C') s=s+"00";
				else s=s+"11";
			}
		}
	}
	cout<<s;
	return 0;
}
