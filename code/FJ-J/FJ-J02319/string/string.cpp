#include<bits/stdc++.h>
using namespace std;
long long k[200005], ans;
char l[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i] >> l[i];
	}
	int le = 1, ri = n;
	while(le <= ri)
	{
		if(l[le] == l[ri])
		{
			if (k[le] > k[ri])
			{
				k[le] -= k[ri];
				ri--;
			}
			else if (k[le] < k[ri])
			{
				k[ri] -= k[le];
				le++;
			}
			else
			{
				le++;
				ri--;
			}
		}
		else
		{
			if (k[le] > k[ri])
			{
				ans += k[ri];
				k[le] -= k[ri];
				ri--;
				
			}
			else if (k[le] < k[ri])
			{
				ans += k[le];
				k[ri] -= k[le];
				le++;
			}
			else
			{
				ans += k[le];
				le++;
				ri--;
			}
		}
	}
	cout << ans;
	return 0;
}
