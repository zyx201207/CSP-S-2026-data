#include<iostream>
#include<cstdio>

using namespace std;

const int N=2e5+5;

long long n,ans,l,r,p,a[N];
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			p=min(a[l],a[r]);
			a[l]-=p;
			a[r]-=p;
		}
		else
		{
			p=min(a[l],a[r]);
			ans+=p;
			a[l]-=p;
			a[r]-=p;
		}
		if(a[l]==0)  l++;
		if(a[r]==0)  r--;
	}
	cout<<ans;
	return 0;
}
