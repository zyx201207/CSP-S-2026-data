//nlogn
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],q[N],ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(q,0,sizeof q);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mi=a[1];
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(int r=1;r<=n;r++)
	{
		int l=1,rr=r,mid;
		while(l<rr)
		{
			mid=(l+rr)/2;
			if((r-mid+1)*a[r]-(q[r]-q[mid-1])<=m)rr=mid;
			else l=mid+1;
//			cout<<mid<<" "<<r<<" "<<(r-mid+1)*a[r]<<" "<<q[r]<<" "<<q[mid-1]<<"\n";
		}
		if(r-l+1>ans)ans=r-l+1;
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
