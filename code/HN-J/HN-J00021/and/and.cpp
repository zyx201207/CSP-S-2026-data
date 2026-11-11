#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[35];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=30;++j)
		{
			if(a[i]&(1<<j))
			{
				++cnt[j];
			}
		}
	}
	int ans=0,i;
	for(i=30;i>=0;i--)
	{
		if(cnt[i]>=m)
		{
			ans=(1<<i);
			break;
		}
	}
	if(ans==0)
	{
		cout<<0;
		return 0;
	}
	for(i=i-1;i>=0;i--)
	{
		for(int j=i;j>=0;--j)
		{
			cnt[j]=0;
		}
		for(int j=1;j<=n;++j)
		{
			for(int k=i;k>=0;--k)
			{
				if(((a[j]&ans)==ans)&&(a[j]&(1<<k)))
				{
					++cnt[k];
				}
			}
		}
		for(int j=i;j>=0;j--)
		{
			if(cnt[i]>=m)
			{
				ans|=(1<<j);
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
