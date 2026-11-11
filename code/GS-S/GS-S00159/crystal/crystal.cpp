#include <bits/stdc++.h>
using namespace std ;
int n , a[500005] , m ;
long long ans , sum , cha ;
bool denchafou ;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m ;
	denchafou = 1 ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] ;
	}
	sort(a + 1 , a + n + 1);
	cha = a[2] - a[1] ;
	for(int i = 3 ; i <= n ; i++)
	{
		if(a[i] - a[i - 1] != cha)
		{
			denchafou = 0 ;
			break ;
		}
	}
	if(denchafou)
	{
		
	}
	for(int i = n ; i >= 1 ; i--)
	{
		sum = 0 ;
		sum += 1 ;
		cha = 0 ;
		for(int j = i - 1 ; j >= 1 ; j--)
		{
			int del = a[i] - a[j] ;
			if(cha + del <= m)
			{
				sum++;
				cha += del ;
			}
			else
			{
				break ;
			}
		}
		ans = max(ans , sum);
	}
	cout << ans << endl ;
	return 0 ;
}
