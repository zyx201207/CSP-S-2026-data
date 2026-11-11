#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long a[MAXN],cf[MAXN];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans;
	long long m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort (a+1,a+n+1);
	for (int i=2;i<=n;++i)
	{
		cf[i]=cf[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for (int i=1;i<n;++i)
	{
		for (int j=i+1;j<=n;++j)
		{
			if (cf[j]-cf[i]<=m)
			{
				ans=max(ans,j-i);
			}
			else{
				break;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
