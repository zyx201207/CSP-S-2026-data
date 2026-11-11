#include<bits/stdc++.h>
using namespace std;
int n,m,a[520000],aa[520000];
int s[350430],top,cx[350430];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int top=1;
		for(int j=1;j<=m;j++)
		s[j]=0;
		for(int j=1;j<=n;j++)
		aa[j]=0;
		for(int j=i;j<=n;j++)
		{
			aa[top]=a[j];
			if(s[a[j]]>0)
			top=s[a[j]];
			else
			s[a[j]]=top;
			top++;
		}
		for(int j=1;j<top;j++)
		cout<<aa[j]<<" ";
		cout<<endl;
		for(int j=1;j<top;j++)
		cx[aa[j]]++;
	}
	for(int i=1;i<=m;i++)
	cout<<cx[i]<<" ";
}