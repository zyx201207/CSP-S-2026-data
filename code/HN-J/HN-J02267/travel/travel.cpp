#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s;
long long x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<4;i++)s[i] = '0';
	if(a==c)
	{
		s[0] = '1';
		if(b[1]==d[1])
		{
			s[1] = '1';
			if((b[2]>='A' &&b[2]<='C' &&d[2]>='A' &&d[2]<='C') ||(b[2]>='D' &&b[2]<='F' &&d[2]>='D' &&d[2]<='F'))
			{
				s[2] = '1';
				if((b[2]=='D' &&d[2]=='F')||(b[2]=='F' &&d[2]=='D'))s[3] = '1';
				if((b[2]=='A' &&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C' &&d[2]=='B'))s[3] = '1';
			}
		}
	}
	for(int i=0;i<4;i++)cout<<s[i];
	return 0;
}
