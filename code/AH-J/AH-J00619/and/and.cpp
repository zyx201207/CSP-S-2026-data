#include<bits/stdc++.h>
using namespace std;
struct guo
{
	long long t,k,y;
}a[2000005];
bool cmp(guo x1,guo x2)
{
	if(x1.k!=x2.k)
		return x1.k>x2.k;
	else
		return x1.t>=x2.t;
}
long long n,m,r,l,x,s,maxn=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		x=a[i].t;
		while(x!=0)
		{
			x=x/2;
			a[i].k++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m+1;i++)
	{
		s=a[i].t;
		for(int j=1;j<=m;j++)
		{
			s=s&a[j+i-1].t;
		}
		maxn=max(maxn,s);
	}
	cout<<maxn;
	return 0;
}
