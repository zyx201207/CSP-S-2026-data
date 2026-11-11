#include <bits/stdc++.h> 
using namespace std;

int a[500005],b[500005],dp[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxn = 0;
		for (int i =1;i<=n;i++)
		{
			int p = 0;
			for (int j = i;j>=1;j--)
				p+=a[i]-a[j];
			//cout<<p<<' ';
			if (p==m)
			{
				if(i>maxn)
				maxn=i;
			}
		}
	cout<<maxn;
	return 0;
}
