#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],sa[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sa[i]=sa[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			int val=a[i]*(i-mid+1)-(sa[i]-sa[mid-1]);
			if(val>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
}
/*
14:50-14:54 sol
14:55-15:01  duipai
*/
