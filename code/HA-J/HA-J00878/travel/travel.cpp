#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	char q,w;
	for(int i=0;i<3;i++)
	{
		if(!(c[i]>='A'&&c[i]<='Z'))
		{
			q+=c[i];
		}
		if(!(d[i]>='A'&&d[i]<='Z'))
		{
			w+=d[i];
		}
	}
	if(q==w)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char e=min(c[2],d[2]);
	char r=max(c[2],d[2]);
	if(r<='C'||e>='D')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(e+1==r&&e!='C')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
