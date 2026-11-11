#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[500005];
int ans;

int enr(int x,int y)
{
	return a[y]*(y-x)-sum[y-1]+sum[x-1];
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int i=1,j=1;
	while(j<=n)
	{
		int k=enr(i,j);
		if(k>m)
		{
			if(i==j)
			{
				i++;
				j++;
			}
			else
				i++;
		}
		else if(k<=m)
		{
			ans=max(ans,j-i+1);
			j++;
		}
	}
	cout << ans<< "\n";
	return 0;
}
