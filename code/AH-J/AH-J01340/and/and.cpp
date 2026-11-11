#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 2;
long long up[31] , lg[31] , a[M];
int idx , ans_id;
void func(long long t)
{
	idx = 0;
	while(t)
	{
		lg[++idx] += (t % 2);
		t /= 2;
	}
	return;
}
bool cmp(long long xx , long long yy)
{
	return xx > yy;
}
bool check(long long t)
{
	idx = 0;
	while(t)
	{
		++idx;
		if(idx == ans_id && (t % 2) == 1)
			return true;
		t /= 2;
	}
	return false;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    long long x;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
	{
    	cin >> a[i];
    	func(a[i]);
	}
	sort(a + 1 , a + n + 1 , cmp);
	long long ans = LLONG_MAX;
	up[1] = 1;
	for(int i = 2 ; i <= 30 ; i++)
		up[i] = up[i - 1] * 2;
	for(int i = 30 ; i >= 1 ; i--)
		if(lg[i] >= m)
		{
			ans_id = i;
			break;
		}
	for(int i = 1 ; i <= n ; i++)
	{
		if(check(a[i]) && m > 0)
		{
			ans &= a[i];
			m--;
		}
	}
	cout << ans;
    return 0;
}
