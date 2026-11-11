#include <bits/stdc++.h>
using namespace std;
string ca,sa,sb,cb;
bool f = 1,k = 1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	for (int i = 0;i < 2;i++)
	{
		if (ca[i]!=cb[i])
		{
			f = 0;
			break;
		}
	}
	for (int i = 0;i < 2;i++)
	{
		if (sa[i]!=sb[i])
		{
			k = 0;
		}
	}
	int a = (int)(sa[sa.size()-1]-'A');
	int b = (int)(sb[sb.size()-1]-'A');
	if (f)
	{
		cout <<"1";
		if (k)
		{
			cout <<"1";
			if ((a<=2&&b<=2)||(a>2&&b>2))
			{
				cout <<"1";
				if (abs(a-b)==1)
				{
					cout <<"1";
				}
				else{
					cout <<"0";
				}
			}
			else{
				cout <<"00";
			}
		}
		else{
			cout <<"000";
		}
	}
	else{
		cout <<"0000";
	}

} 
