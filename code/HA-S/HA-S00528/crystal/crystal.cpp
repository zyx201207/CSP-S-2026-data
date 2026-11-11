#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],t[500005],v[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			v[j]=a[i]-a[j];
		for(int j=i;j>=0;j--)
		{
			if(c[i]+v[j]<=m)
			{
				c[i]+=v[j];
				t[i]++;
			}
		}
	}
	sort(t,t+n);
	cout<<t[n-1];
	return 0;
}
