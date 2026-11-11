#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+9;
int n,m,a[N],qi[N],ho[N],ans;
int can(int mid,int zh)
{
	int ha=qi[zh]-qi[mid-1];
	int cha=(zh-mid+1)*a[zh]-ha;
	if(cha<=m)return 1;
	return 0;
}
signed main()
{
//	cout<<14*14*500000;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)qi[i]=qi[i-1]+a[i];
	for(int i=n;i;i--)ho[i]=ho[i+1]+a[i];
	int l=1,s=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i,z=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(can(mid,i))r=mid-1,z=mid;
			else l=mid+1;
		}
//		cout<<z<<"??\n";
		ans=max(ans,i-z+1);
//		cout<<ans<<"##\n";
//		while(a[i]*(i-l+1)-(qi[i]-qi[]))
	}
	cout<<ans;
	return 0;
}
