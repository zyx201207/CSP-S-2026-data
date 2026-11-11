#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long n,m;
	cin >> n >> m;
	vector <unsigned long long> vec(n);
	unsigned long long a;
	for (int i = 0;i < n;i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	unsigned long long ans = vec[m - 1];
	for (unsigned long long i = m - 2;i > 0;i--)
	{
		ans |= vec[i];
	}
	cout << ans;
	return 0;
}
