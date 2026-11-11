#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[100005],vis[100005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,answer=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		int ans=a[l];
		vis[l]=1;
		for(int i=2;i<=m;i++)
		{
			int ma=0,ls=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j])continue;
				if((ans&a[j])>ma)
				{
					ma=(ans&a[j]);
					ls=j;
				}
				if(ma>=ans)
				{
					break;
				}
			}
			if(ls==0)
			{
				ans=0;
				break;
			}
			ans=ma;
			vis[ls]=1;
		}
		for(int i=1;i<=n;i++)vis[i]=0;
		answer=max(answer,ans);
	}
	cout<<answer;
	return 0;
}
