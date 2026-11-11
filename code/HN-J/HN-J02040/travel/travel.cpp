#include<bits/stdc++.h>
using namespace std;
int x,y;
char a,b;
string x1;
string y11;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x1>>y>>y11;
	a=x1[2],b=y11[2];
	if(x==y)
	{
		cout<<1;
		if(x1[0]==y11[0]&&x1[1]==y11[1])
		{
			cout<<1;
			if((a<='C'&&b<='C')||(a>'C'&&b>'C'))
			{
				cout<<1;
				if((a>'C'&&b>'C')||(a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='B'&&b=='C')||(b=='B'&&a=='C'))
					cout<<1;
				else
					cout<<'0';
			}
			else
				cout<<'0'<<'0';
		}
		else
			cout<<'0'<<'0'<<'0';
	}
	else
		cout<<'0'<<'0'<<'0'<<'0';
	return 0;
}
