#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,ar[200005],ar2[40];

int cmp(int x,int y)
{
	return x>y;
}

void dfs(long long a,long long b,long long c)
{
	if(a == m)
	{
		ans = max(ans,b);
		return ;
	}
	for(int i = c+1;i<n;i++)
	{
		if(b&ar[i]>=ans)
		{
			dfs(a+1,b&ar[i],i);
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int z = 1,x,y = 1;
	ar2[0] = 1;
	for(int i = 1;i<=30;i++)
	{
		ar2[i] = ar2[i-1]*2;
	}
	for(int i = 0;i<n;i++)
	{
		cin>>ar[i];
		x = 0;
		if(ar[i]!=i) y = 0;
		for(int j = 0;j<=30;j++)
		{
			if(ar2[j] == ar[i]+1)
			{
				x = 1;
				break;
			}
		}
		if(x == 0) z = 0;
	}
	if(z)
	{
		sort(ar,ar+n);
		cout<<ar[n-m];
		return 0;
	}
	if(y)
	{
		sort(ar,ar+n,cmp);
		long long f = ar[0];
		for(int i = 1;i<m;i++)
		{
			f&=ar[i];
		}
		cout<<f;
		return 0;
	}
	sort(ar,ar+n,cmp);
	for(int i = 0;i<n;i++)
	{
		dfs(1,ar[i],i);
	}
	cout<<ans;
	return 0;
}
