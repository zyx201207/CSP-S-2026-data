#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,m,a[2000005],b[10005][10005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ans=a[n]-a[n-1];
		if(m/ans%2==1)
		{
			cout<<0;
		}
		else
		{
			cout<<n-m/ans-1;
		}
		cout<<endl;
	}
	return 0;
}
