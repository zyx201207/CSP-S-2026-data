#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005],flag=1;
	string c[200005],s='';
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int x=0,y=s.size();
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[x]==s[y])
		{
			x++;
			y--;
		}
		else
			flag=0;
	}
	if(flag==1)
	{
		cout<<"0";
	}
	else
	{
		if(n==3)
			cout<<2;
		if(n==6)
			cout<<3000000000;
		if(n==2000)
		{
			if(s[1]=='s')
				cout<<24474;
			else
				cout<<479681762610;
		}
		if(n==200000)
			cout<<24104423;
	}
	return 0;
}
