#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct node{
	ll sum;
	char ch;
}a[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%s", &a[i].sum, &a[i].ch);
	}
	int r = n;
	ll ans = 0;
	for(int l = 1; l < r; l++)
	{
		ll sum = a[l].sum;
		while(sum >= a[r].sum)
		{
			if(a[l].ch != a[r].ch) ans += a[r].sum;
			sum -= a[r].sum;
			r--;
		}
		if(a[r].sum == 0) r--;
		if(a[l].ch != a[r].ch) ans += sum;
		a[r].sum -= sum;
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
