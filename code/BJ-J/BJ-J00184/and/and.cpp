#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	const int MAX=(1<<30)-1;
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			maxn=max(maxn,x);
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m==2)
	{
		vector<int> a(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n)
	{
		int ans;
		cin>>ans;
		for(int i=2;i<=n;i++)
		{
			int x;
			cin>>x;
			ans&=x;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==n-1)
	{
		vector<int> a(n+1);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int sum=(1<<30)-1;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans<<endl;
		return 0;
	}
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	vector<bool> isGood(n+1,true);
	for(int i=1;i<=n-m;i++)
	{
		long long maxn=0;
		int index=0;
		for(int j=1;j<=n;j++)
		{
			if(!isGood[j]) continue;
			long long sum=MAX;
			for(int z=1;z<=n;z++)
			{
				if(z!=j)
					sum&=a[z];
			}
			//cout<<"sum:"<<sum<<endl;
			if(sum>maxn)
			{
				maxn=sum;
				index=j;
			}
		}
		//cout<<"index:"<<index<<endl;
		a[index]=MAX;
		isGood[index]=false;
	}
	long long ans=MAX;
	for(int i=1;i<=n;i++)
		ans&=a[i];
	cout<<ans<<endl;
	return 0;
}
