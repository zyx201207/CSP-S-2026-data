#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll total[200005];
char c[200005];
ll findmax(int n)
{
	int maxn = -1;
	for (int i = 0;i < n;i++)
	{
		if (total[i] > maxn)
		{
			maxn = total[i];
		}
	}
	return maxn;
}
ll Sum(int n)
{
	ll sum = 0;
	for (int i = 0;i < n;i++)
	{
		sum += total[i];
	}
	return sum;
}
ll CheckCalc(int n,int mid,string s)
{
	ll cnt = 0;
	for (int i = 0;i < n;i++)
	{
		if (s[i] != s[mid + i + 1])
			cnt++;
	}
	return cnt;
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> total[i] >> c[i];
	}
	string s = "";
	if (findmax(n) < 1000000)
	{
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < total[i];j++)
			{
				s += c[i];
			}
		}
	}
	bool flag = true;
	for (int i = 1;i < n;i++)
	{
		if (c[i] != c[i-1])
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << "0";
		return 0;
	}
	ll mid = Sum(n) / 2;
	cout << CheckCalc(n,mid,s);
	return 0;
}
