#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m+1]={0},a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]==1&&a[n]==i)
		{
			cout<<n;
		}
		else if(b[i]==1)
		{
			cout<<1;
		}
		else cout<<i/2;
	}
}

