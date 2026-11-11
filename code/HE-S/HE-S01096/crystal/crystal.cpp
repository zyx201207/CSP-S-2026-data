#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, maxx = 1;
	long long m;
	cin >> n >> m;
	long long a[n + 10];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = n;i > 0;i--)
	{
		if(i <= maxx)
		{
			break;
		}
		long long mm = m;
		int maxxx = 1;
		for(int j = i - 1;j > 0;j--)
		{
			if(a[i] == a[j])
			{
				maxxx++;
			}
			else if(a[i] - a[j] < mm)
			{
				maxxx++;
				mm = mm - (a[i] - a[j]);
			}
			else if(a[i] - a[j] == mm)
			{
				maxxx++;
				break;
			}
			else
			{
				break;
			}
		}
		maxx = max(maxx, maxxx);
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
$omv;ifr>noydzdyfv~~/j?
idomh ms,rd[svr dyf'
omy ,som)_
}
	gtrp[rm)Avtudys;/omA.AtA.dyfom_.
	
|
人民万岁
没有共产党就没有新中国 【
分解解法放假放假放假放假 i 且 vi = i + 1；对于所有 i (m + 1 ≤ i ≤ n 1)，均有 ui = i m 且 vi = i + 1。

*/
