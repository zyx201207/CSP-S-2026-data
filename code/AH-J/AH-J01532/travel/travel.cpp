#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int i,f=0,f1=0,f2=0,f3=0;
	cin>>a>>b>>c>>d;
	int n=a.size()-1,m=b.size()-1;
	for(i=0;i<=n;i++)
	{
		if(a[i]!=c[i]) f=1;
	}
	for(i=0;i<=m;i++)
	{
		if(b[i]>='0'&&b[i]<='9'&&d[i]>='0'&&d[i]<='9'&&b[i]!=d[i])
		{
			f1=1;
		}
		if((b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C')||(b[i]>='D'&&b[i]<='F'&&d[i]>='D'&&b[i]<='F'))
		{
			f2=1;
		}
		if(abs(int(b[i]-d[i]))==1&&f2==1)
		{
			f3=1;
		}
	}
	if(f==0)
	{
		cout<<1;
		if(f1==0) cout<<1<<f2<<f3;
		else cout<<"000";
	}
	else
	{
		cout<<"0000";
	}
}
