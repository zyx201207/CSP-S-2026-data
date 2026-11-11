#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int erfen(vector<long long> vec,long long n)
{
	unsigned long long l = 1,r = vec.size(),mid = (l + r) / 2;
	while (l < r)
	{
		if (vec[mid] >= n)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
		mid = (l + r) / 2;
	}
	return mid - 1;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long n,m;
	cin >> n >> m;
	vector <long long> vec(n);
	vector <long long> c(n);
	for (unsigned long long i = 0;i < n;i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	for (unsigned long long i = 0;i < n;i++)
	{
		c[i] = (vec[i] - m);
	}
	for (unsigned long long i = 0;i < n;i++)
	{
		c[i] = i - erfen(vec,c[i]) + 1;
	}
	cout << *max_element(c.begin(),c.end());
	return 0;
}
