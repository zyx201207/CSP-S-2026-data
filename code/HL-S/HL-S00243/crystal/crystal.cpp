#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long dp[20][500005];
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[1][i] = 0;
	}sort(a + 1,a+1+n);
	int k = log2(n) + 1;
	for (int i = 2; i <= k; i++)
	{
		for (int j = n; j - (1 << (i - 1)) + 1 >= 1;j--)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - (1 << (i - 2))] + (a[j] - a[j - (1 << (i - 2))]) * (1 << (i - 2));
			if (dp[i - 1][j] == -1 || dp[i - 1][j - (1 << (i - 2))] == -1) dp[i][j] = -1;
			if (dp[i][j] > m) dp[i][j] = -1;
		}
	}
	for (int i = 1;i <= k;i++){
		//for(int j = 1;j <= n;j++) 
			//cout << dp[i][j] << ' ';
		//cout << endl;
	}
	int tar = 0;
	//cout << 'A' << endl;
	for(int i = k;i >= 1;i--)
	{
		bool fl = 0;
		for (int j = n; j - (1 << (i - 1)) + 1 >= (1 << (tar - 2)) + 1;j--) 
		{
			//cout << 'C' << endl;
			if (dp[i][j] != -1)
			{
				//cout << 'D' << endl;
				fl = 1;
				break;
			}
		}
		if (fl)
		{
			tar = i;
			break;
		}
		//cout << 'E' << endl;
	}
	//cout << 'B' << endl;
	cout << tar << endl;
	long long ans = 0;
	long long out = 0;
	long long used = 0;
	//cout << (1 << (tar - 2)) + 1 << ' ' << n << ' ' << (1 << (tar - 1)) << endl;
	for (int j = pow(2,tar - 1),i = 1; j <= n;j++,i++) 
	{
		if(dp[tar][j] == -1) continue;
		used = used + dp[tar][j] * i;
		//cout << used << endl;
		if (used <= m) ans++;
		else
		{
			out = max(ans,out);
			i = 0;
			used = dp[tar][j] * i;
			ans = 0;
		}
	}
	cout << max(ans,out) + pow(2,tar - 1) - 1;
}
