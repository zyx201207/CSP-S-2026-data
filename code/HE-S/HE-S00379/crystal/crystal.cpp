#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n, m;
int a[N];
int ans = 0;
bool used = 0, p = 0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n; i++)
	{
		cin >> a[i];
	}
	int M = m;
	if(n <= 5000)
	{
		
		int have[5005];
		for(int i = 1;i <= n; i++)
		{
			m = M;
			int cha[5005];
			memset(cha,-1,sizeof(cha));
			ans = 0;
			for(int j = 1;j <= n; j++)
				cha[j] = a[i] - a[j];
			
//			for(int i = 1;i <= n; i++) cout << cha[i] << ' ';
//			cout << '\n';
			
			sort(cha + 1, cha + 1 + n);
			for(int i = 1;i <= n; i++)
			{
				if(cha[i] >= 0) 
				{
//					if(cha[i] == 0) {
//						ans++;
//						if(used) p = 1;
//						else used = 1;
//					}
					if(m - cha[i] > -1) 
					{
						m -= cha[i];
//						cout << m <<' ';
						ans++;
					}
					else break;
				}
			}
//			if(p)ans--;
//			cout << ans <<' ';
			have[i] = ans;
		}
		int cnt = 0;
		for(int i = 1;i <= n; i++)
			cnt = max(cnt, have[i]);
		cout << cnt << '\n';
	} //能贪，但是贪不满
	else
	{
		int cha;
		int b = a[n] - a[n - 1];
		cha = b;
		if(cha == 1)
		{
			cout << m/2-1 <<'\n';
			return 0;
		}
		while(m -= b)
		{
			m -= b;
			b += cha;
			ans++;
		}
		cout << ans << '\n';
	}
//	特殊性质 A：对于所有 i (1 ≤ i ≤ n)，均有 ai = i。
//	特殊性质 B：a1, a2, . . . , an 构成等差数列。
	
	return 0;
}
/*
RP来,Rp来 
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
