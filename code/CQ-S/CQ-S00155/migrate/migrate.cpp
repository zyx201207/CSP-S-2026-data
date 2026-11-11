#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			cin>>a[i];
			if(a[i]-a[i-1]>d)
			{
				flag=1;
			}
		}
		if(flag)
		{
			cout<<0<<'\n';
			continue;
		}
		cout<<n-2*2+1<<'\n';
	}
	return 0;
} 
