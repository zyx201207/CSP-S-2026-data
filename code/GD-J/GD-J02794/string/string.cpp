#include <iostream>
using namespace std;

long long a[200005];
long long st[200005];
long long en[200005];

char c[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cin >> c[i];
	}
	long long num = 1;
	for(int i = 1; i <= n; i++)
	{
		st[i] = num;
		num += a[i];
		en[i] = num - 1;
	}
	long long tail = n, head = 1;
	while(tail != head)
	{
		if(en[head] - st[head] > en[tail] - st[tail])
		{
			if(c[tail] != c[head])
			{
				ans += en[tail] - st[tail] + 1;
			}
			st[head] += en[tail] - st[tail] + 1;
			tail--;
		}
		else if(en[head] - st[head] < en[tail] - st[tail])
		{
			if(c[tail] != c[head])
			{
				ans += en[head] - st[head] + 1;
			}
			en[tail] -= en[head] - st[head] + 1;
			head++;
		}
		else if(en[head] - st[head] == en[tail] - st[tail])
		{
			if(tail <= head) break;
			if(c[tail] != c[head])
			{
				ans += en[head] - st[head] + 1;
			}
			head++;
			tail--;
		}
	}
	cout << ans;
	return 0;
}
