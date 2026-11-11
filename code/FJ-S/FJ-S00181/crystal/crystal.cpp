#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
bool cmp(long long a,long long b) 
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int maxn=-1e9;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
		if((b[i]+m)/i*1.0==a[i+1])
		{
			maxn=max(maxn,i+1);
		}
		else if((b[i]+m-1)/i*1.0>=a[i])
		{
			maxn=max(maxn,i);
		}
	}
	cout << maxn;
	return 0;
}
