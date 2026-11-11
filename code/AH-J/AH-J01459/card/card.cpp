#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int arr[N];
int cnt[M], ans[N], num[M];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	int q = n;
	while(q--)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		for(int i = n - q; i <= n; i++)
		{
			if(cnt[arr[i]] > 0)
			{
				for(int j = cnt[arr[i]]; j < i; j++)
					cnt[ans[j]] = 0, ans[j] = 0;
				ans[i] = arr[i];
				cnt[arr[i]] = i;
			}
			else
				cnt[arr[i]] = i, ans[i] = arr[i];
		}
		for(int i = 1; i <= m; i++)
			if(cnt[i] > 0)
				num[i] += 1;
	}
	for(int i = 1; i <= m; i++)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}
