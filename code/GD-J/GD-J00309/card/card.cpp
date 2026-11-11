#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,q[300005],cnt[300005],r,a[500005],ff=0;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			ff=1;
		}
		if(a[i]==a[i-1])
		{
			cnt[a[i]]++;
		}
	}
	if(ff==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout<<i<<" "; 
			}
		}
		return 0;
	}
	for(int k=1;k<=n;k++)
	{
		memset(q,0,sizeof(q));
		r=0;
		for(int i=k;i<=n;i++)
		{
			int flag=1;
			for(int j=1;j<=r;j++)
			{
				if(q[j]==a[i])
				{
					flag=0;
					r=j;
					break;
				}
			}
			if(flag)
			{
				q[++r]=a[i];
			}
		}
		for(int i=1;i<=r;i++)
		{
			cnt[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
