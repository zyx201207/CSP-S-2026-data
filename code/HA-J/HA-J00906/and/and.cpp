#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int a[200005];
int p[200005];
int mmax=0;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				int q=a[i]&a[j];
				if(q>mmax)
				{
					mmax=q;
				}
			}
		}
		cout<<mmax;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}

