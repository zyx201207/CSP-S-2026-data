#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

int n,a[N],sum;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> a[i] >> c[i];
	int l=1,r=n;
	while (l<=r)
	{
		if (a[l]<a[r])
		{
			if (c[l]!=c[r]) sum+=a[l];
			a[r]-=a[l],l++;
		}
		else if (a[l]>a[r])
		{
			if (c[l]!=c[r]) sum+=a[r];
			a[l]-=a[r],r--;
		}
		else
		{
			if (c[l]!=c[r]) sum+=a[l];
			l++,r--;
		}
	}
	cout << sum << '\n';
	return 0;	
}
