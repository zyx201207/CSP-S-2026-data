#include<bits/stdc++.h>
using namespace std;
int s[2010];
int tmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn = -1;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+1+n,tmp);
	printf("%d",s[3]);
	return 0;
}
