#include <bits/stdc++.h>
using namespace std;
int n,m,a[2000002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=n;i>=1;i--)
		{
			cout<<n;
		}
	}
	
}
