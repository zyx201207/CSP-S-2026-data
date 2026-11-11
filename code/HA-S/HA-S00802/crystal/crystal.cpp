#include<bits/stdc++.h>
using namespace std;
#define int long long
//暴力：枚举每个目标数值，检查每颗低于目标值水晶的差值，于与m比较
//优化思路：对于枚举目标值，改用二分法； 
int n,s[500010],m,maxx,minn; 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		maxx = max(s[i],maxx);
		minn = min(s[i],minn);
	}
	int l = minn,r = maxx,sum,ans; 
	while (l < r)
	{
		//cout << 1;
		int i = (l + r) / 2;
		//cout << "!" << i << endl;
		sum = 0,ans = 0;
		for (int j = 1;j <= n;j++)
		{
			if (s[j] <= i)
			{
			//	cout << "!";
				sum += (i - s[j]);
				ans++;
			}
		}
		if (sum <= m)
		{
			l = i + 1;
		}
		else
		{
			r = i;
		}
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
