#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],sum=INT_MIN,b[200005],h=1,yh;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=n-m+1;i--)
	{
		b[h]=a[i];
		h++;	
	}
	yh=b[1];
	for(int i=1;i<h;i++)
	{
		yh&=b[i];
	}
	cout<<yh;
}
