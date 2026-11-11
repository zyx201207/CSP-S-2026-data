#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int num[200005];
char s[200005];
long long ans,sum;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> num[i] >> s[i];
		sum += num[i];
	}
	long long ll = 1,rr = sum;
	int l = 1,r = n;
	while (ll < rr)
	{
		if (s[l] != s[r])
		{
			ans += min(num[l],num[r]);
		}
		int kk1 = ll + num[l] - 1,kk2 = n - rr + num[r];
		if (kk1 < kk2) ll += num[l],l++;
		else if (kk1 > kk2) rr -= num[r],r--;
		else ll += num[l],l++,rr -= num[r],r--;
	}
	cout << ans - 1;
	
	return 0;
}
