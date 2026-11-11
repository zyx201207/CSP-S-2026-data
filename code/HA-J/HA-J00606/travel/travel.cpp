#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,s,d,f;
	cin>>a>>s>>d>>f;
	char x,c;
	int i=0,o=0,p=0,u=0;
	if(a[0]==d[0]&&a[1]==d[1]&&a.size()==d.size())
	{
		i=1;
		cout<<1;
			if(s[0]==f[0]&&s[1]==f[1])
		{
			o=1;
			cout<<1;
			if((s[2]=='A'||s[2]=='C'||s[2]=='B')&&(f[2]=='A'||f[2]=='C'||f[2]=='B'))
			{
					p=1;
					cout<<1;
					x=s[2];
					c=f[2];
				int x1=x,c1=c;
					if(x1-1==c1||c1-1==x1)
					u=1,cout<<1;
			}
			else if((s[2]=='D'||f[2]=='F')&&(s[2]=='D'||f[2]=='F'))
			{
					p=1;
					cout<<1;
					if((s[2]=='F'&&f[2]=='D')||(s[2]=='D'||f[2]=='F'))
					u=1,cout<<1;
			}
		
		}
		
	}
	if(i==0)
	cout<<0;
	if(o==0)
	cout<<0;
	if(p==0)
	cout<<0;
	if(u==0)
	cout<<0;
}

