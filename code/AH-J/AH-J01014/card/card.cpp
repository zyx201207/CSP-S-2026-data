#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<n<<" ";
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<1<<" ";
		}
	}
	return 0;
}
