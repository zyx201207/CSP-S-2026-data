#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt[500005],zui[500005],ans[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		zui[a[i]]=i;
		ans[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int l=i;
		l=zui[a[l]];
		l++;
		cnt[a[i]]+=ans[i];
		ans[l]+=ans[i];
		ans[i]=0;
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}

