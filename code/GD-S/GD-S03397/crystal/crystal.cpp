#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],b[N],ans,num;
long long m;
int main()
{
	freopen("crystal2.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(i<=ans)
		{
			break;
		}
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(m>b[mid]-num)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-r);
		num+=a[i];
	}
	cout<<ans;
	return 0;
}
