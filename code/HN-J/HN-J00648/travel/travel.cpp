#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int p=(a[0]-'0')*10+(a[1]-'0');
	int q=(c[0]-'0')*10+(c[1]-'0');
	int m=(b[0]-'0')*10+(b[1]-'0');
	int n=(d[0]-'0')*10+(d[1]-'0');
	int x=b[2]-'A';
	int y=d[2]-'A';
	if(p!=q)
	{
		cout<<"0000";
	 } 
	else
	{
		if(m!=n)
		{
			cout<<"1000";
		}
		else
		{
			if(!((x<=2 && y<=2)||(x>2 && y>2)))
			{
				cout<<"1100";
			}
			else
			{
				if(x-y==2 || y-x==2)
				{
					cout<<"1110";
				}
				else
				{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
 } 
