#include<bits/stdc++.h>
using namespace std;
int n,m,b[300005];
string a,c;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		char ch;
		cin>>ch;
		a+=ch;
	}
	for(int i=0;i<n;i++)
	{
		c=a.substr(0,i);
		for(int j=i-1;j<n;j++)
		{
			int t=c.find(a[j]);
			if(t!=-1)
			{
				c=c.substr(0,c.find(a[j]));
			}
			else
			{
				c+=a[j];
			}
		}
		for(int j=0;j<c.size();j++)
		{
			if(c[j]-'0'==i)
			{
				b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
