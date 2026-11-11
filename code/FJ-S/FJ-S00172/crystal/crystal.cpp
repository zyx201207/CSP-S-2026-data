#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int pre[500005];
int n,m;
int middle_search(int R,int tar)
{
	int l=1,r=R;
	int ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(tar*(R-mid+1)-(pre[R]-pre[mid-1])<=m)
		{
			ans=mid;
			r=mid-1;
		}else
		{
			l=mid+1;
		}
	}
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
	}
	sort(pre+1,pre+n+1);
	int ans=0;
	for(int r=1;r<=n;r++)
	{
		pre[r]+=pre[r-1];
		int l=middle_search(r,pre[r]-pre[r-1]);
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
