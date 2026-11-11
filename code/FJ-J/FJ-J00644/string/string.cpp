#include<bits/stdc++.h>
using namespace std;

const long long N = 1e6;
long long a[N];
char c[N];

long long main () {
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%d",&n);
	for(long long i = 1;i <= n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	long long ret = 0,cl = 0,cr = 0;
	long long l = 1,r = n;
	while(l<=r)
	{
		if(!cl)
		{
			cl += a[l];
		}
		if(!cr)
		{
			cr += a[r];
		}
		if(cl>cr)
		{
			if(c[l]!=c[r])
			{
				ret += cr;
			}
			cl -= cr;
			cr = 0;
			r--;
			
		}
		else if(cl<cr)
		{
			if(c[l]!=c[r])
			{
				ret += cl;
			}
			cr -= cl;
			cl = 0;
			l++;
		}
		else
		{
			if(c[l]!=c[r])
			{
				ret += cl;
			}
			cl = 0;
			cr = 0;
			r--;l++;
		}
	}
	printf("%lld",ret);
	return 0;
}
