#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n , m;
int a[N] , temp[N];
int cnt[M];
int tot;
int check(int x)
{
	for(int i = 1; i <= tot; i++)
		if(temp[i] == x)
			return i;
	return -1;
}
int main()
{		
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i<= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) temp[i] = a[i];
	tot = m;
	for(int i = 1; i <= n; i++)
	{
		if(tot > 0)
		{
			int pos = check(a[i]);
			if(pos > 0)
			{
				for(int j = pos; j <= tot; j++)
				{
					temp[j] = 0;
				}
				tot = pos - 1;
			}
		}
		temp[++tot] = a[i];
		for(int i = 1; i <= tot; i++)
		{
			cnt[temp[i]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}
