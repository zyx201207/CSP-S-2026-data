#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],ans,l,r;
char c[200010];
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
		if(a[l]>a[r]) 
		{
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			c[r]=c[l];
			r--;
		}
		else
		{
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			c[l]=c[r];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
