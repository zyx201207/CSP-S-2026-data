#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],b[500001],s[500001];
int check(int k)
{
	int l=1,r=k;
	long long num=0;
	while(r<=n)
	{
		num=a[r]*k-(s[r]-s[l-1]);
		if(num<=m) return 1;
		l++,r++;
	}
	return 0;
}
void qsort(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	qsort(l,mid);
	qsort(mid+1,r);
	int x=l,y=mid+1,k=l;
	while(x<=mid&&y<=r)
	{
		if(a[x]<a[y]) b[k++]=a[x],x++;
		else b[k++]=a[y],y++;
	}
	while(x<=mid) b[k++]=a[x],x++;
	while(y<=r) b[k++]=a[y],y++;
	for(int i=l;i<=r;i++) a[i]=b[i];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	qsort(1,n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,mid=0;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)==1)
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
