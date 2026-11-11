#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[1000005];
ll maxn;
int main()
{
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]!=a[j])
			{
				maxn=max(maxn,a[i]&a[j]);
			}
			
		}
	}
	cout<<maxn;
	return 0;
}
