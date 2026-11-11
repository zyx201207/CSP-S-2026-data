#include <iostream>
using namespace std;
struct P
{
	int many;
	char k;
} a[200005];
char b[40000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt = 0,ans = 0,sum = 0;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].many >> a[i].k;
		for (int j = sum + 1;j <= sum + a[i].many;j++)
		{
			b[j] = a[i].k;
		}
		sum += a[i].many;
		cnt += a[i].many;
	}
	long long mid = cnt / 2;
	for (long long i = 1,j = cnt;i <= mid;i++,j--)
	{
		if (b[i] != b[j])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
