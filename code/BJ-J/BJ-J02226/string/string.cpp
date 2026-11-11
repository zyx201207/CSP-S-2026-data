#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,cntl,cntr;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	cntl = a[1];cntr = a[n];
	for (int i = 1,j = n;i <= j;)
	{
		if (c[i] == c[j])
		{
			int l = cntl,r = cntr;
			cntl = max(0,l - r);
			cntr = max(0,r - l);
			if (cntl < cntr)
				{i++;cntl=a[i];}
			else if (cntl == cntr)
				{i++;cntl=a[i];j--;cntr=a[j];}
			else
				{j--;cntr=a[j];}
		}
		else
		{
			int l = cntl,r = cntr;
			ans += min(l,r);
			cntl = max(0,l - r);
			cntr = max(0,r - l);
			if (cntl < cntr)
				{i++;cntl=a[i];}
			else if (cntl == cntr)
				{i++;cntl=a[i];j--;cntr=a[j];}
			else
				{j--;cntr=a[j];}
		}
	}
	cout << ans;
	return 0;
}

