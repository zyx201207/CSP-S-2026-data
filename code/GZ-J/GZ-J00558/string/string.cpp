//GZ-J00558 ¶Îãå·²
#include<bits/stdc++.h>
using namespace std;
struct p
{
	int a ;
	char c ; 
};
p s[2010] ;
int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	
	int n ;
	scanf("%d", &n) ;
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d %c", &s[i].a , &s[i].c) ;
	}
	int l = 0 , r = n - 1 ;
	int cntl = 0 , cntr = 0 ;
	int ret = 0 ;
	for( ; l < r ; )
	{
		if(cntl == 0 && cntr > 0) 
		{
			if(s[l].a > cntr)
			{
				cntl = s[l].a - cntr ;
				if(s[l].c != s[r].c)
				{
					ret += s[l].a - cntr ;
				}
				l++;
			}
			if(s[l].a < cntr)
			{
				cntr = cntr - s[l].a ;
				if(s[l].c != s[r].c)
				{
					ret += cntr - s[l].a ;
				}
				l++;
			}
		}
		if(cntl > 0 && cntr == 0) 
		{
			if(cntl > s[r].a)
			{
				cntl = cntl - s[r].a ;
				if(s[l].c != s[r].c)
				{
					ret += cntl - s[r].a ;
				}
				r--;
			}
			if(cntl < s[r].a)
			{
				cntr = s[r].a - cntl ;
				if(s[l].c != s[r].c)
				{
					ret += s[r].a - cntl ;
				}
				r--;
			}
		}
		if(cntl == 0 && cntr == 0) 
		{
			if(s[l].a > s[r].a)
			{
				cntl = s[l].a - s[r].a ;
				if(s[l].c != s[r].c)
				{
					ret += s[l].a - s[r].a ;
				}
				r--;
			}
			if(s[l].a < s[r].a)
			{
				cntr = s[r].a - s[l].a ;
				if(s[l].c != s[r].c)
				{
					ret += s[r].a - s[l].a ;
				}
				l++;
			}
		}
	}
	printf("%d", ret) ;
	return 0 ;
}
