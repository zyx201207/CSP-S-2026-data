#include<bits/stdc++.h>
using namespace std;
int a[500005];
int tong[500005];
int cnt[500005];
long long n,m;
int cc(int x)
{
	for(int i=1;i<=n;i++)
	{
		tong[x]++;
		if(tong[x]>1)
		{
			
			for(int j=1;j<=n;j++)
			{
				tong[a[j]] = 0;
			}
		}
		i++;
	}
	cnt[tong[x]]++;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	long long b = n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cc(a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		long long ans = cnt[tong[a[i]]];
		cout<<ans<<" ";		
	}
	return 0;
}
