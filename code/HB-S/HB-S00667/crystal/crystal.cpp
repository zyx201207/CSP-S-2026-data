#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N] , n , m;
int best = 0;
bool check(int x)
{
	int sum = 0;
	int digit = 0;
	for(int i = 1; i <= n; i++)
	{
		if(digit > m) {break;}
		if(a[i] > x) break;
		if(a[i] <= x) 
		{
			digit += (x - a[i]);
			sum++;
		}
	}
	if(best == 0 && sum > best)
	{
		best = sum;
		return false;
	}
	else best = max(best , sum);
	return sum >= best;
}
void solve_extra()
{
	int kb = a[n] , ans = 0;
	for(int i = 1; i <= n; i++) ans += kb - a[i];
	if(m >= ans) 
	{
		cout << n; 
		return ;
	}
	int l = 1, r = kb;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << best;
}
void solveA_and_B()
{
	int flag;
	int pre[N];
	pre[1] = 0;
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for(int i = n - 1; i >= 1; i--)
	{
		if(m >= pre[i]) { flag = i ; break; } 
	}
	if(m > pre[n - 1]) cout << n;
	else cout << flag + 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 1) {cout << 1; return 0;}
	if(n == 2) 
	{
		int ghk = abs(a[2] - a[1]);
		if(m >= ghk) cout << 2;
		else cout << 1;
		return 0;
	}
	sort(a + 1 , a + n + 1);
	int diff = a[2] - a[1];
	bool flag = false;
	for(int i = 2; i < n; i++)
	{
		if(a[i + 1] - a[i] != diff)
		{
			flag = true;
			break;
		}
	}
	if(!flag)
		solveA_and_B();
	else
		solve_extra();
	return 0;
}
