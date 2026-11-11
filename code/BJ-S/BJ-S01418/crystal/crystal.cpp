#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-(r+1)+1);
	}
	cout<<ans;
	return 0;
}