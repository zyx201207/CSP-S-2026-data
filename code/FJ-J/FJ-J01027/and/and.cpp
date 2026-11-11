#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt=0,ans=0,ax[30][200010],sum[200010],cx[200010];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		sum[++cnt]=i;
		for (int j=29;j>=0;--j)
		  if((x&(1<<j))!=0) ax[j][i]=1;
	}
	for (int i=29;i>=0;--i)
	{
		int cn=0;
		for (int j=1;j<=cnt;++j)
		{
			int x=sum[j];
			if(ax[i][x]==1) cx[++cn]=x;
		}
		if(cn>=m)
		{
			ans+=(1<<i);cnt=cn;
			for (int i=1;i<=cn;++i)
			  sum[i]=cx[i];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
4 2
3 15 12 12
1100000000000000000000000000000
1111000000000000000000000000000
0011000000000000000000000000000
0011000000000000000000000000000
*/
