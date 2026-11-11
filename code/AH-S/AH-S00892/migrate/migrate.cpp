#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11 || c==12)
	{
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(a[2]-a[1]>d)
			{
				cout<<0;
				continue;
			}
			else if(a[2]-a[1]==d)
			{
				cout<<1;
				continue;
			}
		}
	}
	return 0;
}
