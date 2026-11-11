#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j+i]-a[j]<=m)
			{
				cout<<i+1;
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
}
