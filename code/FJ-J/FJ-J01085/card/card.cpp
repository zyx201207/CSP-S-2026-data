#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,s=1;
	cin>>n>>m;
	int a[50010];
	int b[30010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j<n;j++)
		if(a[i]!=a[j])
		{
			b[s]==a[i];
		}
	}
	for(int i=1;i<=s;i++)
	{
		cout<<b[i]<<" ";
	}		
	return 0;
}