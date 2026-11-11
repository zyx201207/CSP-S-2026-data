#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n,a[N],m,mx,mx_ans;

int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	if(m == 1)
	{
		cout << mx;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				mx_ans = (a[i] & a[j]);
			}
		}
		cout << mx_ans;
		return 0;
	}
	return 0;
}
