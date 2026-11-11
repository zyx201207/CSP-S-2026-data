
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i)
			{
				cout<<j<<' ';
				break;
			}
		}
	}
	return 0;
}
