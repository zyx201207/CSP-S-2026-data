#include<bits/stdc++.h>
using namespace std;
int a[500010];
int d[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	d[0] = 0;
	for(int i=1;i<n;i++)
	{
		d[i] = a[i]-a[i-1];
	}
	int ans=0;
	int l=0,r=0;
	int q=0;
	while(r<n)
	{
		if(q<=m)
		{
			r++;
			if(r>=n)
			{
				break;
			}
			q+=(r-l)*d[r];
		}
		else
		{
			l++;
			q-=a[r]-a[l-1];
		}
		if(q<=m)
		{
			ans = max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}
