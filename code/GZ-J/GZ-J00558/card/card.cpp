//GZ-J00558 ∂Œ„Â∑≤
#include<bits/stdc++.h>
using namespace std;

struct p
{
	int l ;
	int a ; 
	int r ;
};
p s[5010] ;

int tong[3010] ;
int main()
{
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	int n , m ;
	scanf("%d%d", &n , &m );
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d", &s[i].a) ;
		s[i].l = i-1 ;
		s[i].r = i+1 ;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(iny j = i ; j <= n ; j++)
		{
			for(iny k = i ; k <= j ; k++)
			{
				if(s[j].a == s[k].a)
				{
					s[j].l = 0 ;
					s[0].r = j ;
				}
			}
		}
		int k = s[0].r ;
		while(s[k].r != 0)
		{
			tong[s[k].a]++;
			k = s[k].r ;
		}
		for(int j = 1 ; j <= n ; j++)
		{
			s[j].l = j-1 ;
			s[j].r = j+1 ;
		}
	}
	for(int i = 1 ; i <= m ; i++)
	{
		printf("%d ", tong[i]) ;
	}
	return 0 ;
}
