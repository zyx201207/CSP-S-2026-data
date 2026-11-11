#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 5e5 + 10, M = 3e5 + 10;
ll n, m, a[N];
ll cnt[M], pos[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int k = 1;k <= n;k++)
	{
		for(int j = 1;j <= m;j++)
			pos[j] = 0;
		for(int i = k;i <= n;i++)
		{
			if(pos[a[i]] == 0)
				pos[a[i]] = i;//, cout << " new card " << i << " " << a[i] << "\n";
			else
			{
				for(int j = 1;j <= m;j++)
					if(pos[a[j]] > pos[a[i]])
						pos[a[j]] = 0;
				pos[a[i]] = i;
			}
		}
		for(int j = 1;j <= m;j++)
			if(pos[j] != 0)
				cnt[j]++;
//	for(int j = 1;j <= m;j++)
//		cout << cnt[j] << " ";
//		cout << "\n";
	}
	
	for(int j = 1;j <= m;j++)
		cout << cnt[j] << " ";
	return 0;
 } 
