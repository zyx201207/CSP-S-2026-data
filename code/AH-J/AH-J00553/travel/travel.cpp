#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string str;
	getline(cin,str);
	if((str[0]==str[7])&&(str[1]==str[8]))
	{
		cout<<1;
		if((str[3]==str[10])&&(str[4]==str[11]))
		{
			cout<<1;
			if((str[5]<='C'&&str[12]<='C')||(str[5]>'C'&&str[12]>'C'))
			{
				cout<<1;
				if((str[5]+1)==str[12]||(str[5]-1)==str[12])
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
