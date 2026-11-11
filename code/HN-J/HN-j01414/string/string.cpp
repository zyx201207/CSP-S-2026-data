#include<bits/stdc++.h>
using namespace std;

int ux;

int n;
long long s[200006];
char c[200006];
string sh;
long long s_size;
long long ans;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ux=scanf("%d",&n);
	if(ux!=1) return 1;
	for(int i=1;i<=n;i++)
	{
		ux=scanf("\n%lld %c",&s[1],&c[1]);
		if(ux!=2) return 2;
		for(int i=1;i<=s[1];i++)
		{
			sh=sh+c[1];
		}
		s_size=s_size+s[1];
	}
	for(long long i=0;i<=s_size/2-1;i++)
	{
		if(sh[i]!=sh[s_size-1-i])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
3
2 a
2 b
1 c
*/
