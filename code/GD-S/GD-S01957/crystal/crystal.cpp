#include <bits/stdc++.h>
using namespace std;
long long m;
long long a[500005],b[500005];
int n,cnt=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+(i-1)*a[i]-(i-1)*a[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(b[i]-b[j]<=m&&i-j+1>cnt) cnt=i-j+1;
			else if(b[i]-b[j]>m) break;
		}
	}
	cout<<cnt;
	return 0;
}
