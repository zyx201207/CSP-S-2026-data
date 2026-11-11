#include <iostream>
using namespace std;
int n, m;
int a[500010];
int cnt_arr[300010] = {}, v[300010];
bool flag_arr[300010] = {};
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int k = a[i];
		int index_k = i;
		v[i] = k;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] == k)
			{
				v[index_k] = 0;
				for (int c = index_k + 1; c < j; c++)
				{
					v[c] = 0;
				}
				index_k = j;
			}
			v[j] = a[j];
		}
		for (int j = i; j <= n; j++)
		{ 
			if (!flag_arr[v[j]])
			{
				cnt_arr[v[j]]++;
				flag_arr[v[j]] = 1;
			}
			cout << v[j] << ' ';
			v[j] = 0;
		}
		cout << endl;
		for (int j = 1; j <= m; j++) flag_arr[j] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt_arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
