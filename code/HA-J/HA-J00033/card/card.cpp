#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,a[500005],isp[300005];
vector<int>pai;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=n-m;i--)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}
