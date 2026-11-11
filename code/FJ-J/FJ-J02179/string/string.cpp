#include<bits/stdc++.h>
using namespace std;
long long a[200100],l,sum[200100],n,ans;
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
	l=sum[n];
	long long middle=(l+1)>>1;
	int l=1,r=n,id;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(sum[mid]<=middle)l=mid+1,id=mid;
		else r=mid-1;
	}
	id=l;
	l=1,r=n;
	while(l<id&&id<=r)
	{
		while(a[r]>a[l])a[r]-=a[l],ans+=(c[l]==c[r]?0:a[l]),l++;
		a[l]-=a[r];
		ans+=(c[l]==c[r]?0:a[r]);
		r--;
	}
	ans+=(c[l]==c[id]?0:a[l]);
	cout<<ans;
	return 0;
}