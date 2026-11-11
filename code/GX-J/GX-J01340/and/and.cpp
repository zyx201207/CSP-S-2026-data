#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,m;
int a[maxn];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin >> n >> m;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>mx)
		{
			mx=a[i];
		}
	}
	if(m==1)
	{
		cout << mx;
	}
	if(m==n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
	}
	if(m==2)
	{
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]&a[j]>ans)
				{
					ans=a[i]&a[j];
				}
			}
		}
		cout << ans;
	}
	else{
		int ans=-1;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=m;i++)
		{
			ans=ans&a[i];
		}
		cout << ans;
	}
	return 0;
}
