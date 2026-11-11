#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m;
ll a[N];
ll sum[N],idx[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		sum[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		idx[i]=(i-1)*(a[i]-a[i-1])+idx[i-1];
		if(idx[i]>m)
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}
