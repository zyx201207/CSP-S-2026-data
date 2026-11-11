#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[200001];
long long cnt;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int l = 1,r = n;
	while (l < r)
	{
		if (c[l] == c[r])
		{
			if (a[l] > a[r]) a[l] -= a[r],r--;
			else if (a[l] < a[r]) a[r] -= a[l],l++;
			else l++,r--;
		}
		else
		{
			if (a[l] > a[r]) a[l] -= a[r],cnt += a[r],r--;
			else if (a[l] < a[r]) a[r] -= a[l],cnt += a[l],l++;
			else cnt += a[l],l++,r--;
		}
	}
	cout << cnt;
	return 0;
}

