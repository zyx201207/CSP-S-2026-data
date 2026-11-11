#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(i==a[1]) cout<<"1 ";
			else cout<<"0 ";
		}
		return 0;
	}
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	return 0;
} 
