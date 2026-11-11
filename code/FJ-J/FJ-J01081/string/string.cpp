#include <iostream>
#include <cstdio>
using namespace std;
struct node
{
	long long cnt;
	char c;
};
long long n, m, a[200005] = {};
char s[200005] = {};
node w[200005] = {}, v[200005] = {};

int main()
{
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> s[i], m += a[i];
	long long pos1 = 0, pos2 = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(sum+a[i] <= m/2) w[++pos1] = {a[i], s[i]};
		else
		{
			w[++pos1] = {m/2-sum, s[i]};
			break;
		}
		sum += a[i];
	}
	sum = 0;
	for(int i = n; i >= 1; i--)
	{
		if(sum + a[i] <= m/2) v[++pos2] = {a[i], s[i]};
		else
		{
			v[++pos2] = {m/2-sum, s[i]};
			break;
		}
		sum += a[i];
	}
	long long sum1 = 0, sum2 = 0, ans = 0, r = 1;
	for(int l = 1; l <= pos1; l++)
	{
		sum1 += w[l].cnt;
		while(true)
		{
			if(sum2+v[r].cnt <= sum1) sum2 += v[r].cnt, ans += (v[r].c != w[l].c)*v[r].cnt;
			else
			{
				sum2 += v[r].cnt-sum1;
				ans += (v[r].c != w[l].c) * (v[r].cnt-sum2);
				v[r].cnt -= sum2;
				break;
			}
			r++;
		}
	}
	cout << ans;
	return 0;
}
