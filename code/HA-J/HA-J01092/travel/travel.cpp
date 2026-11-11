#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string m,n;
	cin>>a>>m>>b>>n;
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<'1';
		if(m[0]==n[0]&&m[1]==n[1])
		{
			cout<<'1';
			if((m[2]>'C'&&n[2]>'C')||(m[2]<='C'&&n[2]<='C'))
			{
				cout<<'1';
				if((m[2]=='A'&&n[2]=='C')||(n[2]=='A'&&m[2]=='C'))
				{
					cout<<'0';
				}
				else
				{
					cout<<'1';
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
