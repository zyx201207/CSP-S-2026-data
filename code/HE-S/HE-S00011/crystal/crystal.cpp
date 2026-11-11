#include<bits/stdc++.h>
using namespace std;
long long m;
int n,nl[500050],cz[500050],a[500050];
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>nl[i];
	}
	sort(nl,nl+n);
	cz[0]=nl[1]-nl[0];
	for(int i=1;i<n;i++)
	{
		cz[i]=nl[i+1]-nl[i];
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=cz[i-1]*i+a[i-1];
	}
	int k=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=m)
		{
			k++;
		}
		else
		{
			break;
		}
	}
	cout<<k;
	return 0;
}
