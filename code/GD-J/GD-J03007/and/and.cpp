#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const long long N=2e5+10;
long long n,m;
long long a[N];
long long cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans1=a[1];
	long long ans2=a[2];
	for(long long i=2;i<=m;i++)
	{
		ans1=ans1&a[i];
	}
	for(long long i=2;i<=m+1;i++)
	{
		ans2=ans2&a[i];
	}
	cout<<max(ans1,ans2);
	return 0;
}

