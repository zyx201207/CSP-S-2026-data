#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
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
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1) ans=1;
		if((a[i]*(a[i-1]))/2>m)
		{
			ans=i-1;
			break;
		}
	}
	cout << ans;
	return 0;
 } 
 //25
