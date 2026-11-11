#include<bits/stdc++.h>

using namespace std;

#define MAXN 500010

int n;
long long m;
long long a[MAXN],tmp[MAXN],ans=0;

void dfs(int x)
{
	if(x==0)
	{
		long long cnt=1;
		for(int i=1;i<=n;i++)
		{
			if(i==1)	continue;
			if(tmp[i]!=tmp[i-1])
			{
				ans=max(ans,cnt);
				cnt=1;
			}
			else cnt++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		tmp[i]++;
		dfs(x-1);
		tmp[i]--;
	}
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=5)
	{
		memcpy(tmp,a,sizeof(a));
		dfs(m);
		cout<<ans<<endl;
	}
	else
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=0;
				for(int k=i;k<=j;k++)
				{
					cnt+=(a[j]-a[k]);
				}
				if(cnt<=m)
				{
					ans=max(ans,(long long)j-i+1);
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
