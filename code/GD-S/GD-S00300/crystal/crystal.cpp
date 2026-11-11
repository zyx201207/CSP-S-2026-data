#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans;
long long b[N];
void qsort(long long a[],int l,int r)
{
	int i=l,j=r;
	long long mid=a[l+rand()%(r-l+1)];
	while(i<=j)
	{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if(i<=j) swap(a[i++],a[j--]);
	}
	if(l<j) qsort(a,l,j);
	if(i<r) qsort(a,i,r);
}
long long sum(int l,int r)
{
	return b[r]-b[l-1];
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	qsort(a,1,n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int i=1,j=1;
	while(i<=j&&j<=n)
	{
		if(a[j]*(j-i+1)-sum(i,j)<=m) ans=max(ans,(long long)(j-i+1)),j++;
		else i++;
	}
	cout<<ans;
	return 0;
}
