#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char a[5],b[5],c[5],d[5];
	cin>>a[0]>>a[1]>>c[0]>>c[1]>>c[2]>>b[0]>>b[1]>>d[0]>>d[1]>>d[2];
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";
		if(c[0]==d[0]&&c[1]==d[1])
		{
			cout<<"1";
			if((c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C'))
			{
				cout<<"1";
				if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if(c[2]>='D'&&c[2]<='F'&&d[2]>='D'&&d[2]<='F')
			{
				cout<<"11";
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
