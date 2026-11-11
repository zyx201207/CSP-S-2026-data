#include<bits/stdc++.h>
using namespace std;
int m,n;
long long a[200010];
long long maxv=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				maxv=max(maxv,a[i]&a[j]);
			}
		}
		cout<<maxv;
		return 0;
	}
	maxv=a[n];
	for(int i=n-1;i>=0;i--)
	{
		m--;
		maxv&=a[i];
		if(m==0)break;
	}
	cout<<maxv;
	return 0;
} 
