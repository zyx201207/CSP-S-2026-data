#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=0;
	for(int i=0;i<n-1;i++)
	{
		sum+=a[n-1]-a[i];
	}
	if(sum<=m)
	{
		cout<<n<<endl;
		return 0;
	}
	int time=0;
	for(int i=n-1;i>=0;i--)
	{
		sum=1;
		int ans=0;
		for(int j=i-1;j>=0;j--)
		{
			ans+=a[i]-a[j];
			if(m>=ans&&j==0)
			{
				cout<<sum+1<<endl;
				return 0;
			}
			if(m>=ans&&j>0)
			{
				sum++;
			}
			if(m<ans)
			{
				break;
			}
		}
			time=max(time,sum);
	}
	if(time==0)
	{
		cout<<1<<endl;
		return 0;
	}
	cout<<time<<endl;
	return 0;
} 
