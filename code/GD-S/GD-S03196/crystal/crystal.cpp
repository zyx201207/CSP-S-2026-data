#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll a[N],fz[N];
int n;
ll m,sum;
void merge(int l,int r)
{
	if(l >=r ) return;
	int mid = (l + r ) / 2;
	merge(l,mid); merge(mid + 1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j <= r)
	{
		if(a[i] < a[j]) fz[k++] = a[i++];
		else fz[k++] = a[j++];	
	} 
	while(i<=mid) fz[k++] = a[i++];
	while(j<=r) fz[k++] = a[j++];
	for(int i=l;i<=r;i++) a[i] = fz[i];
}
ll q[N];
bool check(int len)
{
	for(int i=len;i<=n;i++)
	{
		ll sum = q[i] - q[i - len - 1];
		ll num = a[i] * len - sum;
		if(num <= m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);	
	} 
	merge(1,n);
//	q[1] = a[i]
	for(int i=1;i<=n;i++)
	{
		q[i] = q[i-1] + a[i];
	}
	int l=1,r=n,ans=1;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<ans;
	return 0;
}
