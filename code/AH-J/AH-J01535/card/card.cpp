#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],s[300005],t[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool t=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
			t=0;
	}
	if(t)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout<<i<<' ';
			}
		}
	}
	else
	{
		if(a[n]<a[n-1])
		{
			cout<<n<<' '<<n-1;
		}
		else
		{
			cout<<n-1<<' '<<n;
		}
	}
	return 0;
}
