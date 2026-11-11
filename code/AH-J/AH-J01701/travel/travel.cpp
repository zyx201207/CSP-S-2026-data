#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string s,t;
	cin>>x>>s>>y>>t;
	if(x!=y) 
	{
		cout<<"0000";
		return 0;
	}
	else 
	{
		cout<<1;
		int a,b;
		char p,q;
		a=(s[0]-'0')*10+s[1]-'0';
		b=(t[0]-'0')*10+t[1]-'0';
		p=s[2],q=t[2];
		if(p-'A'>q-'A') swap(p,q);
		if(a!=b)
		{
			cout<<"000";
			return 0;
		}
		else 
		{
			cout<<1;
			if((p=='A'&&q=='B')||(p=='A'&&q=='C')||(p=='B'&&q=='C')||(p=='D'&&q=='F'))
			{
				cout<<1;
				if(p!='A'||q!='C') 
				{
					cout<<1;
					return 0;
				}	
				else 
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}
