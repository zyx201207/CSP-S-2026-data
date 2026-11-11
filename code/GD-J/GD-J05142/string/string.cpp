#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int now=1;
	for (int i=2;i<=n;i++)
	{
		if(c[i]==c[now]) 
		{
			a[now]+=a[i];
			a[i]=0;
		}
		else 
		{
			now++;
			c[now]=c[i];
			a[now]=a[i];
		}
	}
	int l=1,r=now;
	long long zns=0,yns=0,as=0;
	while(l<=r)
	{
		while(l<=r&&zns!=0)
		{
			a[l]=max(0ll,a[l]-zns);
			zns=max(0ll,zns-a[l]);
			l++;
		}
		while(l<=r&&yns!=0)
		{
			a[r]=max(0ll,a[r]-yns);
			yns=max(0ll,yns-a[r]);
			r--;
		}
		if (c[l]==c[r])
		{
			if(a[l]>a[r]) yns=abs(a[l]-a[r]);
			else zns=abs(a[l]-a[r]);
			as+=abs(a[l]-a[r]);
		}
		else 
		{
			as+=min(a[l],a[r]);
			if(a[l]>a[r]) yns=abs(a[l]-a[r]);
			else zns=abs(a[l]-a[r]);
		}
		l++;
		r--;
	}
	cout<<as;
	return 0;
}
