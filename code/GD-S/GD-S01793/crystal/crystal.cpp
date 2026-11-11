#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005],b[500005];
void qsort(int l,int r)
{
	if(l>=r) return;
	int i=l,j=r;
	long long mid=a[(l+r)/2];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	qsort(1,n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i-1];
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(b[i]-b[mid])<=m) r=mid;
			else l=mid+1;
		}
		if(a[i]*(i-l)-(b[i]-b[l])<=m) ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0; 
}
