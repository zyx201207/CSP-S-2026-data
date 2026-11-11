#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a[4];
	for(int i=0;i<=3;i++)
		cin>>a[i];
	if(a[0]==a[2])
	{cout<<"1";
		if(a[1][0]==a[3][0]&&a[1][1]==a[3][1])
			{cout<<"1";
				if((a[1][2]=='A'||'B'||'C')&&(a[3][2]=='A'||'B'||'C'))
				{cout<<"1";
					if(a[1][2]=='A'&&a[3][2]=='B')
					cout<<"1";
					else
					if(a[1][2]=='B'&&a[3][2]=='A')
					cout<<"1";
					else
					if(a[1][2]=='B'&&a[3][2]=='C')
					cout<<"1";
					else
					if(a[1][2]=='C'&&a[3][2]=='B')
					cout<<"1";
				else
				if((a[1][2]=='A')&&(a[3][2]!='B'))
				cout<<"0";
				if((a[1][2]=='B')&&(a[3][2]!='A'))
				cout<<"0";
				
				if((a[1][2]=='B')&&(a[3][2]!='C'))
				cout<<"0";
				if((a[1][2]=='C')&&(a[3][2]!='B'))
				cout<<"0";
				}	
				else
				if((a[1][2]=='D'||a[1][2]=='F')&&(a[3][2]=='F'||a[3][2]=='D'))
				cout<<"11";
				else
				if((a[1][2]=='C'||a[1][2]=='D')&&(a[3][2]=='D'||a[3][2]=='C'))
				cout<<"00";
				}
				else
				cout<<"000";
			}
	if(a[0]!=a[2])
	cout<<"0000";
	return 0;
}
