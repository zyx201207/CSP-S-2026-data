#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], a_[500005];
int mnum=-1;
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	a_[1]=0;
	for(int i = 2; i<=n;i++)
	{
		a_[i] = a[i] - a[i-1];
	}
	for (int i = n; i >= 1; i--)
	{
		long long sum = 0, su = 0;
		int num = 1;
		for (int j = i; j >= 1; j--)
		{
			sum += a_[j];
			su += sum;
			if (su <= m) num++;
			else break; 
		}
		mnum = max(mnum,num);
	}
	cout << mnum;
	return 0;
} 
