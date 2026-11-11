#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],qzh[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		qzh[i]=qzh[i-1]+a[i];
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int gs=i-mid+1;
			int xy=a[i]*gs-(qzh[i]-qzh[mid-1]);
			if(xy<=m)
			{
				ans=max(ans,gs);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
