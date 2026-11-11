#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,maxn,tmp=1,a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans+=(i-tmp)*(a[i]-a[i-1]);
		if(ans>m)
		{
			maxn=max(maxn,i-tmp);
			for(int j=tmp;j<i;j++)
			{
				ans-=(a[i]-a[j]);
				tmp++;
				if(ans<=m)
				{
					break;
				}
			}
			maxn=max(maxn,i-tmp+1);
		}
	}
	cout<<maxn;
	return 0;
}
