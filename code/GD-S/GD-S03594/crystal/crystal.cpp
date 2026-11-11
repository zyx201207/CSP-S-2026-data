#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+100;
int n,m;
int ans=0;
int a[MAXN];
int sum[MAXN];
int st,ed;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];	
	}
	st=1;
	for (int i=1;i<=n;i++)
	{
		int s=sum[i]-sum[st-1];
		if (a[i]*(i-st+1)-s>m)
		{
			st++;
			i--;
		}
		else
		{
			ans=max(ans,i-st+1);
		}
	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=n;j>=i+1;j--)
//		{
//			int s=sum[j]-sum[i-1];
//			if (a[j]*(j-i+1)-s<=m)
//			{
//				ans=max(ans,j-i+1);
//				break;
//			}
//		}
//	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
