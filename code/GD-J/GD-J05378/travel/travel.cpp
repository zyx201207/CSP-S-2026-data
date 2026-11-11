#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a!=c) 
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << 1;
		for(int i=1;i<=b.size();i++)
		{
			if(b[i]>='0'&&b[i]<='9'&&d[i]>='0'&&d[i]<='9')
			{
				if(b[i] == d[i]) cout << 1;
				else
				{
					cout << "000";
					return 0;
				}		
			}
			else
			{
				if((b[3]!='D'&&b[3]!='F')&&(d[3]!='D'||d[3]!='F'))
				{
					cout << 1;
					break;
				} 
				else if((b[3]!='A'&&b[3]!='B'&&b[3]!='C')&&(d[3]!='A'&&d[3]!='B'&&d[3]!='C')) 
				{
					cout << 1; 
					break;
				}
				else if((b[3]=='A'||b[3]=='B'||b[3]=='C')&&(d[3]=='D'||d[3]=='F')) cout << 0;
				else if((b[3]=='D'||b[3]=='F')&&(d[3]=='A'||d[3]=='B'||d[3]=='C')) cout << 0;	
			}
		}
	}
	if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B'))
	{
		cout << 1;
	}
	else if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
	{
		cout << 1;
	}
	else cout << 0;
	return 0;
 } 
