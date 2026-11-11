#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1;
void c(int l,int r,long long k)
{
	if(l>=r)	return;
	long long mid=(l+r)/2,num=1,sum=0,x=mid-1,y=mid+1;
	while(x>=1&&y<=n)
	{
		if(a[mid]-a[x]>a[y]-a[mid])
		{
			if(sum+a[y]-a[mid]>m)	break;
			sum+=a[y]-a[mid];
			y++;
			num++;
		}
		else
		{
			if(sum+a[mid]-a[x]>m)	break;
			sum+=a[mid]-a[x];
			x--;
			num++;
		}
	}
	while(x>=1)
	{
		if(sum+a[mid]-a[x]>m)	break;
		sum+=a[mid]-a[x];
		x--;
		num++;
	}
	while(y<=n)
	{
		if(sum+a[y]-a[mid]>m)	break;
		sum+=a[y]-a[mid];
		y++;
		num++;
	}
	if(num<k)	return;
	maxn=num;
	c(l,mid,num);
	c(mid+1,r,num);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)	cin >> a[i];
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		c(1,n,0);
	}
	else
	{
		int mid=(1+n)/2,l=mid-1,r=mid+1,sum=0;
		while(l>=1&&r<=n)
		{
			if(sum+a[r]-a[mid]>m)	break;
			sum+=a[r]-a[mid];
			r++;
			maxn++;
			if(sum+a[mid]-a[l]>m)	break;
			sum+=a[mid]-a[l];
			l--;
			maxn++;
		}
		while(l>=1)
		{
			if(sum+a[mid]-a[l]>m)	break;
			sum+=a[mid]-a[l];
			l--;
			maxn++;
		}
		while(r<=n)
		{
			if(sum+a[r]-a[mid]>m)	break;
			sum+=a[r]-a[mid];
			r++;
			maxn++;
		}
	}
	cout << maxn;
	return 0;
}
