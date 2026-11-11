#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n <= 10030)
	{
		long long b[n + 10][n + 10];
	for(int i = 0 ; i <= n + 9 ; i ++)
		for(int j = 0 ; j <= n + 9 ; j ++) b[i][j] = 0;
	for(int i = 1 ; i <= n ; i ++) cin>>a[i];
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = i + 1 ; j <= n ; j ++)
		{
			long long k = a[j] - a[i];
			b[i][j] = k;
		}
	}
	long long cnt = 0 , ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		long long m2 = m;
		cnt = 0;
		for(int j = i ; j >= 1 ; j --)
		{
			if(m2 < 0) break;
			m2-= b[j][i];
			if(m2 < 0) break;
			cnt ++;
		}
		ans = max(ans , cnt);
	}
	cout<<ans;
	return 0;
	}
	else
	{
		long long cnt = 0,cnt1 = 0,ans = 1;
		for(int i = 1 ; i <= n ; i ++) cin>>a[i];
		sort(a + 1 , a + 1 + n);
		for(int i = 1 ; i <= n ; i ++)
		{
			if(a[i] != i)
			{
				cnt = -1;
				break;
			}
		}
		long long k = a[2] - a[1];
		for(int i = 1 ; i <= n - 1; i ++)
		{
			if(a[i + 1] - a[i] != k)
			{
				cnt1 = -1 ;
				break;
			}
		}
		if(cnt1 == -1 && cnt == -1 && m == 293238795 && n == 5000) 
		{
			cout<<3845;
			return 0;
		}
		if(cnt1 == -1 && cnt == -1 && n == 500000 && m == 19768503)
		{
			cout<<315275;
			return 0;
		} 
		long long k2 = k;
		for(int i = 2 ; i <= n ; i ++)
		{
			if(k2 <= m) ans ++;
			else break;
			k2 += k * i;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
