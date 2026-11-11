#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=1;
	vector<long long> a,mx;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
	for (int i=1;i<n;i++)
	{
		long long hav=m,j=i-1,x=1;
		while (hav-(a[i]-a[j])>=0&&j>=0)
		{
			hav-=(a[i]-a[j]),x++,j--;
		}
		maxx=max(maxx,x);
	}
	cout<<maxx;
	return 0;
}
