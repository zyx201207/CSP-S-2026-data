#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct node
{
	unsigned long long a;
	char c;
};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned long long n;
	cin >> n;
	vector <node> vec(n);
	unsigned long long l = 0,r = n - 1,isize = 0,ans = 0;
	for (unsigned long long i = 0;i < n;i ++)
	{
		cin >> vec[i].a >> vec[i].c;
		isize += vec[i].a;
	}
	for (unsigned long long i = 0;i < isize / 2;i++)
	{
		if (vec[l].a == 0)
		{
			l++;
		}
		if (vec[r].a == 0)
		{
			r--;
		}
		if (vec[l].c != vec[r].c)
		{
			ans++;
		}
		vec[l].a--;
		vec[r].a--;
	}
	cout << ans;
	return 0;
}
