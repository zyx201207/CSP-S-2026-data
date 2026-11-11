#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b,c,d;
ll len;
ll x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>a>>b>>c>>d;
	if(b==d)
	{
		cout<<"0000";
		return 0;
	}
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	for(int i=0;i<=3;i++)
	{
		if(b[i]<='9'&&b[i]>='0')
		{
			if(b[i]!=d[i])
			{
				cout<<0;
				len=0;
				break;
			}
			else
			{
				len=1;
			}
		}
	}
	if(len==1)
	{
		cout<<1;
		if(b[2]>='A'&&b[2]<='Z')
		{
			if((b[2]<='C'&&b[2]>='A')&&(d[2]<='C'&&d[2]>='A'))
			{
				if(b[2]=='C'&&d[2]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[2]=='D'&&d[2]=='C')
				{
					cout<<"00";
					return 0;
				}
				cout<<1;
			}
			else if((b[2]<='D'&&b[2]>='F')&&(d[2]<='D'&&d[2]>='F'))
			{
				if(b[2]=='C'&&d[2]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[2]=='D'&&d[2]=='C')
				{
					cout<<"00";
					return 0;
				}
				cout<<1;
			}
			else
			{
				if(b[2]=='C'&&d[2]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[2]=='D'&&d[2]=='C')
				{
					cout<<"00";
					return 0;
				}
			}
			x=b[2]-'A',y=d[2]-'A';
			if(y-x==1||x-y==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			if((b[3]<='C'&&b[3]>='A')&&(d[3]<='C'&&d[3]>='A'))
			{
				if(b[3]=='C'&&d[3]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[3]=='D'&&d[3]=='C')
				{
					cout<<"00";
					return 0;
				}
				cout<<1;
			}
			else if((b[3]<='D'&&b[3]>='F')&&(d[3]<='D'&&d[3]>='F'))
			{
				if(b[3]=='C'&&d[3]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[3]=='D'&&d[3]=='C')
				{
					cout<<"00";
					return 0;
				}
				cout<<1;
			}
			else
			{
				if(b[3]=='C'&&d[3]=='D')
				{
					cout<<"00";
					return 0;
				}
				if(b[3]=='D'&&d[3]=='C')
				{
					cout<<"00";
					return 0;
				}
			}
			x=b[3]-'A',y=d[3]-'A';
			if(y-x==1||x-y==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}
