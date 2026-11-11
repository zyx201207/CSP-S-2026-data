#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],maxn=-2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
}
