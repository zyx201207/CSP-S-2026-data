#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N=2e5+5;

int n,m,ans,a[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==1)
	{
		ans=a[1];
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else
	{
		ans=a[m];
	}
	cout<<ans;
	return 0;
}
