#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int a[500010];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,Max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n,j=n,k=0;i>=1;k-=(i-j-1)*(a[i]-a[i-1]),i--)
	{
		for(;j>=1&&k+a[i]-a[j]<=m;k+=a[i]-a[j],j--);
		Max=max(Max,i-j);
	}
	cout<<Max;
	return 0;
}
