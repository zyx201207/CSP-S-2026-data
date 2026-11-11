#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxa=0,ans;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		for(int i=1;i<=n;i++) maxa=max(maxa,a[i]);
		cout<<maxa;
	}
	else if(m==n)
	{
		maxa=a[1];
		for(int i=2;i<=n;i++) maxa=maxa & a[i];
		cout<<maxa;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=++i;j<=n;j++) maxa=max(maxa,a[i] & a[j]);
		cout<<maxa;
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1) ans=a[2];
			else ans=a[1];
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				ans=ans & a[j];
			}
			maxa=max(maxa,ans);
		}
		cout<<maxa;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[n-m+1];
	}
	return 0;
}

