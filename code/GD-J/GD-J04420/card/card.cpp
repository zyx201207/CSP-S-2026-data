#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;i++)
	{
		if (a[i]==a[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
