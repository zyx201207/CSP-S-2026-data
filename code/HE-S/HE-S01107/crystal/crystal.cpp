#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1,k,ans=0,z=1;
	long long x=0,y=a[1];
	while(r<n)
	{
		r++;
		while(l<r)
		{
			k=(l+r+1)/2;
			if(x+a[r]-y<=m)
			{
				x+=a[r]-y;
				y=a[k];
				z++;
				break;
			}
			x-=y-a[l];
			l++;
			y=a[(r+l)/2];
			z--;
		}
		ans=max(ans,z);
	}
	cout<<ans;
	return 0;
} 
