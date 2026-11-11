#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
void solve()
{
	scanf("%d%d",&n,&k);
	if (k==n) 
	{
		puts("0");
		return ;
	}
	int m=n/2;
	if (k>=m)
	{
		puts("1");
		return ;
	}
	printf("%d\n",(m-k+1+3)/4+1);
	return ;
}
void solve1()
{
	scanf("%d%d",&n,&k);
	if (k==n) 
	{
		puts("0");
		return ;
	}
	puts("1");
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while (T--)
	{
		if (c==1)
		{
			solve1();
		}
		else
		{
			solve();
		}
	}
	return 0;
}

