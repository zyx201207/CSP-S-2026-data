#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int s[n];
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> s[i];
	}
	int maxn = 0;
	for (int i = 0;i < n ;i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((s[i] & s[j]) >= maxn)
			{
				maxn = s[i] & s[j];
			}			
		}
	}
	cout << maxn;
	return 0;
}
