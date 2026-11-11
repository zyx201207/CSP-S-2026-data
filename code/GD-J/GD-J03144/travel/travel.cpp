#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	int p=0,q=0;
	int lena=a.size(),lenb=b.size(),lenx=x.size(),leny=y.size();
	for(int i=0;i<lena;i++)
		p=p*10+(a[i]-'0');
	for(int i=0;i<lenb;i++)
		q=q*10+(b[i]-'0');
	if(p!=q)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	p=0;
	q=0;
	for(int i=0;i<lenx-1;i++)
		p=p*10+(x[i]-'0');
	for(int i=0;i<leny-1;i++)
		q=q*10+(y[i]-'0');
	if(p!=q)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(x[2]>='A' && x[2]<='C')
	{
		if(y[2]>'C')
		{
			cout<<"00";
			return 0;
		}
		cout<<"1";
	}
	else
	{
		if(y[2]<'D')
		{
			cout<<"00";
			return 0;
		}
		cout<<"1";
	}
	if(abs(x[2]-y[2])==1)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
