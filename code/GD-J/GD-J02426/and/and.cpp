#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=31;i>=0;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			bool flag=true;
			for(int k=31;k>=i+1;k--)
			{
				if((ans&(1<<k))&&(!(a[j]&(1<<k)))) flag=false;
			}
			if(!flag) continue;
			sum+=(a[j]&(1<<i))!=0;
		}
		if(sum>=m)
		{
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
