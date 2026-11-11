#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
long long n , m , ans = -1;
long long a[200005];
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) scanf("%lld" , &a[i]);
	sort(a + 1 , a + n + 1);
	if(m == 1)
	{
		cout << a[n];
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1;i < n;i++) for(int j = i;j <= n;j++) ans = max(ans , (a[i] & a[j]));
		cout << ans;
		return 0;
	}
	bool flag = true;
	for(int i = 1;i <= n;i++)
	{
		if((a[i] & a[i] + 1) != 0)
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		cout << a[n - m + 1];
		return 0;
	}
	if(a[n] < 4)
	{
		long long cnt1 = 0 , cnt2 = 0 , cnt3 = 0 , cnt4 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 0) cnt1++;
			if(a[i] == 1) cnt2++;
			if(a[i] == 2) cnt3++;
			if(a[i] == 3) cnt4++;
		}
		int ans1 = max(cnt1 , max(cnt2 , max(cnt3 , cnt4))) , temp;
		if(cnt1 == ans1) temp = 0;
		else if(cnt2 == ans1) temp = 1;
		else if(cnt3 == ans1) temp = 2;
		else if(cnt4 == ans1) temp = 3;
		if(ans1 >= m)
		{
			cout << temp;
			return 0;
		}
		if(temp == 0 || temp == 2) cout << 0;
		else if(temp == 1 || temp == 3)
		{
			if((cnt2 + cnt4) > m) cout << 2;
			else cout << 0;
		}
		return 0;
	}
	if(m == n)
	{
		long long ans = a[1];
		for(int i = 2;i <= n;i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == (n - 1))
	{
		long long sum1 = a[1] , ans = -1;
		for(int i = 2;i <= n;i++) sum1 &= a[i];
		for(int i = 1;i <= n;i++) ans = max(ans , (sum1 & a[i]));
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
