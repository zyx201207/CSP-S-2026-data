#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+5;
int c,t,n,m,a[N],diff[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int cnt=0;
		cin>>n>>m;
		memset(diff,0,sizeof(diff));
		if(n<=3)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
			diff[i]=a[i+1]-a[i];
		for(int i=1;i<n;i++)
			if(diff[i]>m)
				cnt++;
		if(a[4]-a[1]<=m)
			cout<<0<<endl;
		else
			cout<<n-m-1-cnt<<endl;
	}
	return 0;
}
