#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,s,t;
	string a,b;
	cin>>x>>a>>y>>b;
	s=int((a[0]-'0')*10+a[1]-'0');
	t=int((b[0]-'0')*10+b[1]-'0');
	if (x!=y)
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;	
	}
	else
	{
		cout<<1;
		if (s==t)
		{
			cout<<1;
			if ('A'<=a[2] && a[2]<='C' && 'A'<=b[2] && b[2]<='C')
			{
				cout<<1;
				if (char(a[2]+1)==b[2] || char(b[2]+1)==a[2]) cout<<1;
				else cout<<0;
				return 0;
			}
			if ('D'<=a[2] && a[2]<='F' && 'D'<=b[2] && b[2]<='f')
			{
				cout<<1;
				if (char(a[2]+1)==b[2] || char(b[2]+1)==a[2]) cout<<1;
				else cout<<0;
				return 0;
			}
			cout<<0;
			cout<<0;
		}
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	return 0;
 } 
 //02 01C 02 01D
