#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a;
	cin>>y>>b;
	int  aa=a[0]-'0'*10+a[1]-'0',bb=b[0]-'0'*10+b[1]-'0';
	bool xx=0,yy=0,fl=0;
	if(a[2]<='C') xx=1;
	if(b[2]<='C') yy=1;

	if(x!=y)
	{                   
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if(aa!=bb) cout<<"000";
	else
	{
		cout<<"1";
			if(xx!=yy) cout<<"00";
			else
			{
				cout<<"1";
				
				if(a[2]=='D'&&b[2]=='F') fl=1;
				if(abs(a[2]-b[2])!=1&&fl!=1) cout<<"0";
				else
				{
					cout<<"1";
				}
			}
		}
	}
	
	return 0;	
	}