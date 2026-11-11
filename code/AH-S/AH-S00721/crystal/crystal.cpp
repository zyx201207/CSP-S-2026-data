#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],maxn=-1;
void dfs(int step,int m1)
{
	if(m1==0)
	{
		int s=1,cnt=-1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
				s++;
			else
			{
				cnt=max(cnt,s);
				s=1;
			}
		}
		maxn=max(maxn,cnt);
		return;
	}
	if(step>n)
		return;
	for(int i=0;i<=m1;i++)
	{
		a[step]+=i;
		dfs(step+1,m1-i);
		a[step]-=i;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		sum[i]=a[i+1]-a[i];
	dfs(1,m);
	cout<<maxn;
	return 0;
}
