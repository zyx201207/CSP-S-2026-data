#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		if(a[n]!=a[n-1])
		{
			if(a[n]==1)
			{
				cout<<n<<" "<<n-1;
			}
			else {
				cout<<n-1<<" "<<n;
			}
		}
		else
		{
			if(a[n]==1)
			{
				cout<<n<<" 0";
			}
			else
			{
				cout<<n-1<<" 0";
			}
		}
		return 0;
	}
	if(m==1)
	{
		cout<<n;
	}
	return 0;
}