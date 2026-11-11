#include <bits/stdc++.h>;
using namespace std;

long long a[500005];
long long n,m;
long long ans = 0;
void dfs(long long i,long long cnt,long long mm)
{
	if(mm<0)
	{
		ans=max(cnt-1,ans);
		return ;
	}
	if(i>n)
	{
		ans=max(cnt-1,ans);
		return ;
	}
	dfs(i+1,cnt+1,mm-(a[i+1]-a[i])*cnt);
	if(cnt == 1)dfs(i+1,cnt,mm);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000)
	{
		int cnt = 0;
		long long d=a[n]-a[n-1];
		long long i=1;
		while(m>0)
		{
			m=m-i*d;
			cnt++;
		}
		cout<<cnt-1;
	}
	else
	{
		dfs(1,1,m);
		cout<<ans;
	}
	return 0;
}
