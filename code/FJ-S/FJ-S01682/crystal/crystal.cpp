#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=n;i>=2;i--)
	{
		int j=i-1,b=0;
		if (i<ans) break;
		long long x=0;
		while(x<=m && j)
		{
			x+=a[i]-a[j];
			j--;
			if (x<=m) b++;
		}
		ans = max(b,ans);
	}
	cout<<ans+1;
	return 0;
} 
