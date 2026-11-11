#include<bits/stdc++.h>
using namespace std;
long long n,m,a[220000],t,l,r,ans;
char c[220000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(a[l]==a[r])
		{
			if(c[l]!=c[r])
				ans+=a[l];
			l++;
			r--;
		}
		else if(a[r]<a[l])
		{
			if(c[l]!=c[r])
				ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else
		{
			if(c[l]!=c[r])
				ans+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
