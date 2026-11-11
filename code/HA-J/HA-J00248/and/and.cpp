#include <bits/stdc++.h>
using namespace std;
long long n,m;
int f(int x)
{
	long long ans = 1;
	for(int i = 1;i <= x;i++)
	{
		ans *= 10;
	}
	return ans;
}
int q(int x)
{
	long long num = 1;
	for(int i = 1;i <= x;i++)
	{
		num *= 2;
	}
	return num;
}
int cmd(long long n)
{
	string s = "";
	while(n > 0)
	{
		s += n%2;
		n = n / 2;
	}
	long long num = 0;
	for(int i = 0;i < s.length();i++)
	{
		num += (s[i])*f(i);
	}
	return num;
}
int w(int y,int x)
{
	return (y/f(x-1))%10;
}
bool cmp(int a,int b)
{
	int c = 0,d = 0;
	for(int i = 1;i <= sizeof(a);i++)
	{
		if(w(a,i) == 1)
		{
			c++;
		}
	}
	for(int i = 1;i <= sizeof(b);i++)
	{
		if(w(b,i) == 1)
		{
			d++;
		}
	}
	return c < d;
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	long long a[n+5];
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i] = cmd(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int t = a[n],r = 0;
	while(a[n] > 0)
	{
		a[n] = a[n] / 10;
		r++;
	}

	for(int i = n-1;i > n - m;i--)
	{
		for(int j = 1;j <= r;j++)
		{
			if((w[t,j]==w[a[i],j]) && (w[t,j]))
			{
				
			}
			else
			{
				t = t - 1*f(j-1);
			}
		}
	}
	long long ans = 0;
	for(int i = 1;i <= sizeof(t);i++)
	{
		ans += w(t,i)*q(i-1);
	}
	cout << ans;
	return 0;
}
