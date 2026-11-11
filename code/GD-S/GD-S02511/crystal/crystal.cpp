#include<bits/stdc++.h>
using namespace std;

const int N=500010;
long long a[N];
long long cnt[100000010];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	int mx=1,xxx=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i]]>mx)
		{
			mx=cnt[a[i]];
			xxx=a[i];
		}
		else if(cnt[a[i]]==mx)
		{
			if(a[i]<xxx)
			{
				mx=cnt[a[i]];
				xxx=a[i];
			}
		}
	}
	if(mx==1)
	{
		int md=0;
		sort(a+1,a+n+1);
		if(n%2==0)md=a[n/2];
		else md=a[n/2+1];
		for(int i=n;i>=1;i--)
		{
			if(a[i]>md)continue;
			int ret=md-a[i];
			m-=ret;
			a[i]=md;
		}
		int ret=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==md)
			{
				ret++;
			}
		}
		cout<<ret;
	}
	else
	{
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]>xxx)
			{
				continue;
			}
			int tot=xxx-a[i];
			m-=tot;
			a[i]=xxx;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==xxx)
			{
				sum++;
			}
		}
		cout<<sum;
	}
	return 0;
} 
