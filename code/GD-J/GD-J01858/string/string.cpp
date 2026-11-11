#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long x;
	char c;
};
int n;
long long ans;
node a[200005],q[200005],p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long sum = 0,num = 0;
	int b;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].c;
		sum += a[i].x;
	}
	for (int i = 1;i <= n;i++)
	{
		num += a[i].x;
		if (num >= sum / 2)
		{
			b = i;
			break;
		}
	}
	for (int i = 1;i <= b;i++)
	{
		if (i != b)
		{
			q[i].x = a[i].x;
		}
		else
		{
			q[i].x = sum / 2 - num + a[i].x; 
		}
		q[i].c = a[i].c;
		if (n - i + 1 != b)
		{
			p[i].x = a[n - i + 1].x;
		}
		else
		{
			p[i].x = num - sum / 2; 
		}
		p[i].c = a[n - i + 1].c;
	}
	int l = 1,r = 1;
	while (l <= b)
	{
		if (q[l].x > p[r].x && q[l].c != p[r].c)
		{
			q[l].x -= p[r].x;
			ans += p[r].x;
			r++;
		}
		else if (q[l].x > p[r].x && q[l].c == p[r].c)
		{
			q[l].x -= p[r].x;
			r++;
		}
		else if (q[l].x < p[r].x && q[l].c != p[r].c)
		{
			p[r].x -= q[l].x;
			ans += q[l].x;
			l++;
		}
		else if (q[l].x < p[r].x && q[l].c == p[r].c)
		{
			p[r].x -= q[l].x;
			l++;
		}
		else if (q[l].c != p[r].c)
		{
			ans += q[l].x;
			l++;
			r++;
		}
		else
		{
			l++;
			r++;
		}
	}
	cout << ans;
	return 0;
} 
