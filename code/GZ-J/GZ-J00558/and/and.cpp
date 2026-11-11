//GZ-J00558 ∂Œ„Â∑≤
#include<bits/stdc++.h>
using namespace std;
int s[100010] ;
int main()
{
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int n , m ;
	scanf("%d%d", &n , &m );
	int ma = 0 , cnt1 ;
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d", &s[i]) ;
		if(ma == 0)
		{
			cnt1 = s[i] ;
		}
		ma = max(ma,s[i]) ;
		cnt1 &= s[i] ;
	}
	if(m == 1) 
	{
		printf("%d", ma) ;
		return 0 ;
	}
	if(m == n)
	{
		printf("%d", cnt1) ;
		return 0 ;
	}
	int cnt = 0 ;
	if(m == 2)
	{
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cnt = max(cnt,s[i]&s[j]) ;
			}
		}
		printf("%d", cnt) ;
		return 0 ;
	}
	return 0 ;
}
