#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], Ans[300005];
void f(int m)
{
	int t[300005] = {0}, d[300005] = {0}, b[500005];
	for(int i = m; i <= n; i++)
	{
		t[a[i]] ++;
		b[i] = a[i];
		if(t[a[i]] > 1)
		{
			for(int j = d[a[i]]; j < i; j++)
			{
				while(b[j] == 0 && j < i - 1) j++;
				t[a[j]] --;
				b[j] = 0;
			}
		}
		d[a[i]] = i;
	}
	for(int i = 1; i <= k; i++) Ans[i] += (t[i] != 0);
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) f(i);
	for(int i = 1; i <= k; i++) cout << Ans[i] << " ";
	return 0;
}
