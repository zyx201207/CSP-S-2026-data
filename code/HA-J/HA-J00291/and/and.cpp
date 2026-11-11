#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxn;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ans=a[1];
	for(int i=1;i<=n;i++)
	{
		ans=ans&a[i];
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	maxn=0;
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(n<=20)
	{
		do{
			int sum=a[1];
			for(int i=1;i<=m;i++)
			{
				sum=a[i]&sum;
			}
			maxn=max(maxn,sum);
		}while(next_permutation(a+1,a+n+1));
		cout<<maxn;
		return 0;
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==3)cnt1++;
		if(a[i]==2)cnt2++;
	}
	if(cnt1>=m)
	{
		cout<<3;
	}
	else if(cnt1+cnt2>=m)
	{
		cout<<2;
	}
	else 
	{
		cout<<0;
	}
	return 0;
}