#include <bits/stdc++.h>
using namespace std;
string s;
int n,a[1000005],ans,l,r;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cin >> s[i];
	}
	l = 1,r = n;
	while(l<=r)
	{
		if(a[r] < 1)
		{
			r--;
		}
		if(a[l] < 1)
		{
			l++;
		}
		int minn = min(a[l],a[r]);
		if(s[l] != s[r] && a[r] >= 1 && a[l] >= 1)
		{
			ans+=minn;
		}		
		a[l]-=minn;
		a[r]-=minn;
	}
	cout << ans;
	return 0;
}
