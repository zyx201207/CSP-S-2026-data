#include<bits/stdc++.h>
using namespace std;
struct h
{
	int c,p;
	char w;
}a[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>a[0].c>>s1>>a[1].c>>s2;
	a[0].p=s1[0]+s1[1]-'0';
	a[1].p=s2[0]+s2[1]-'0';
	a[0].w=s1[2];
	a[1].w=s2[2];
	if(a[0].c==a[1].c)
	{
		cout<<1;
		if(a[0].p==a[1].p)
		{
			cout<<1;
			if(((a[0].w=='A'||a[0].w=='B'||a[0].w=='C')&&(a[1].w=='A'||a[1].w=='B'||a[1].w=='C'))||((a[0].w=='D'||a[0].w=='F')&&(a[1].w=='D'||a[1].w=='F')))
			{
				cout<<1;
			}
			else
			{
				cout<<"00";
				return 0;
			}
			if((a[0].w=='A'&&a[1].w=='B')||(a[1].w=='A'&&a[0].w=='B')||(a[0].w=='B'&&a[1].w=='C')||(a[1].w=='B'&&a[0].w=='C')||(a[0].w=='D'&&a[1].w=='F')||(a[1].w=='D'&&a[0].w=='F'))
			{
				cout<<1;
			}else
			{
				cout<<0;
			}
		}else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
