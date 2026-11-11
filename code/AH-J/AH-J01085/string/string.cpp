#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,l,r,s=0;
	cin>>n;
	l=1,r=n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<=r)
	{
		if(c[l]!=c[r])
		{
			s+=min(a[l],a[r]);
		}
		int t=min(a[l],a[r]);
		a[l]-=t;
		a[r]-=t;
		if(a[l]<=0)
		{
			l++;
		}
		if(a[r]<=0)
		{
			r--;
		}
	}
	cout<<s;
}
