#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	int a[200005];
	int maxn=-1;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}
	else if(m==2)
	{
		int s;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				s=a[i]&a[j];
				maxn=max(maxn,s);
			}
		}
		cout<<maxn;
	}
	else
	{
		sort(a+1,a+1+n);
		int minn;
		minn=min(a[n-1],a[n]);
		cout<<minn;
	}
	return 0;
}
