#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,tmp,mid = 1;
vector<long long> a,h;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	a.insert(a.begin(),0);
	h.insert(h.begin(),0);
	for (long long i = 0;i < n;i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin() + 1,a.end());
	for (long long i = 0;i < n;i++)
	{
		h.push_back(h[i] + a[i + 1]);
	}
	l = r = 1;
	while (n >= r)
	{
		long long cnt = r - l + 1;
		if (cnt * a[r] <= m - h[l - 1] + h[r])
		{
			mid = max(mid,cnt);
			r++;
		}
		else
		{
			l++;
		}
	}
	cout << mid << endl;
}
