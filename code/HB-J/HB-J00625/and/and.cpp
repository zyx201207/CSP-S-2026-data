#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans1;
long long ans;
void dfs(int cnt,int yet,long long s)
{
	if(cnt==m)
	{
		ans=max(ans,s);
		return ;
	}
	if(n-yet+cnt<m) return ;
	dfs(cnt,yet+1,s);
	for(int i=yet+1;i<=n;i++)
	{
		if(cnt==0)
		{
			dfs(cnt+1,i,a[i]);
		}
		else dfs(cnt+1,i,s&a[i]);
	}
}
int main()
{   
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    long long ans2=0;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		ans1=max(ans1,a[i]);
		if(i==1)
		{
			ans2=a[i];
		}
	}
	if(m==1)
	{
		cout<<ans1;
		return 0;
	}
	if(m==n)
	{
		cout<<ans2;
		return 0;
	}
	if(m==n-1)
	{
		long long ans3=0;
		for(int i=1;i<=n;i++)
		{
			long long s=a[1];
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				if(i==1&&j==2) s=a[j];
				s&=a[j];
			}
			ans3=max(s,ans3);
		}
		cout<<ans3;
		return 0;
	}
	dfs(0,0,1);
	cout<<ans;
    return 0;
}
