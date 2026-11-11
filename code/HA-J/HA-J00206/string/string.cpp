#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int num[20005] = {};
	char s[20005] = {};
	long long cnt = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i] >> s[i];

	}
	int r = n;
	for(int l = 1; l <= r;)
	{
		if(num[l] > num[r])
		{
			if(s[l] != s[r])
			{
				cnt += num[r];
			}
			num[l] -= num[r];
			r --;
		}
		else if(num[l] < num[r])
		{
			if(s[l] != s[r])
			{
				cnt += num[l];
			}
			num[r] -= num[l];
			l++;
		}
		else if(num[l] == num[r])
		{
			if(s[l] != s[r])
			{
				cnt += num[l];
			}
			r--;
			l++;
		}
	}
	cout << cnt;
	return 0;
}
