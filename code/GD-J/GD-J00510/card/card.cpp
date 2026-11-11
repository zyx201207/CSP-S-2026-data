#include <bits/stdc++.h>
using namespace std;
int n,m,cnt1[100005],cnt2[100005],ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	string k1 = "",k2 = "";
	for (int i = 0;i < n;i++)
	{
		cin >> ans; 
		k2 += to_string(ans);
		k1 += to_string(ans);
		cnt1[ans]++;
		if (cnt1[ans] >= 2)
		{
			for (int j = k1.find(to_string(ans));j <= k1.size();j++)
			{
				for (int k = 1;k <= n;k++)
				{
					string m1(1,k1[j]);
					if (m1 == to_string(k))
					{
						cnt1[k1[j] - '0']--;
					}
				}
			}
			k1.erase(k1.find(to_string(ans)),i);
		}
	}
	for (int j = 0;j < k1.size();j++)
	{
		cnt2[k1[j] - '0'] ++;
	}
	for (int i = 1;i < n;i++)
	{
		k1 = "";
		memset(cnt1,0,sizeof(cnt1));
		for (int j = i;j < n;j++)
		{
			char ans1 = k2[j];
			string m2(1,ans1);
			k1 += m2;
			cnt1[ans1 - '0']++;
			if (cnt1[ans1] >= 2)
			{
				for (int k = k1.find(ans1 - '0');k <= k1.size();j++)
				{
					for (int q = 1;q <= n;q++)
					{
						string m1(1,k1[q]);
						if (m1 == to_string(q))
						{
							cnt1[k1[q] - '0']--;
						}
					}
				}
				k1.erase(k1.find(ans1 - '0'),j);
			}
		}
		for (int k = 0;k < k1.size();k++)
		{
			cnt2[k1[k] - '0'] ++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		if (cnt2[i] != 0)
		{
			cout << cnt2[i] << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
	return 0;
} 
