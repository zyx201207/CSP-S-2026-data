#include <bits/stdc++.h>
using namespace std;
#define int long long

#define xx and__name__0

const int N=2e5,M=2e5,As=30;
bool a[N+105][As+5];
bool alv[N+105];

signed main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	scanf("%lld %lld",&n,&m);
	for (int i=1; i<=n; i++)
	{
		int xx;
		scanf("%lld",&xx);
		for (int j=As-1; j>=0; j--)
		{
			a[i][j]=(xx&1); xx>>=1;
		}
		alv[i]=1;
	}
	int sum=0;
	for (int j=0; j<30; j++)
	{
		int num=0;
		for (int i=1; i<=n; i++)
		{
			if (alv[i] && a[i][j]) num++;
		}
		if (num>=m)
		{
			for (int i=1; i<=n; i++)
			{
				if (alv[i] && a[i][j]==0)
				{
					alv[i]=0;
				}
			}
		}
		sum<<=1;
		sum|=!!(num>=m);
	}
	printf("%lld",sum);
	return 0;
}

/*
4 2
3 15 12 12

12
*/

/*
5 3
31 3 1 15 7

7
*/
