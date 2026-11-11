#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],l,r;
char x[200005];
long long h;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&m[i]);
		scanf("%s",&x[i]); 
	}
	l=1;
	r=n;
	for(;;)
	{
		if(m[l]<=m[r])
		{
			if(x[l]!=x[r]) h+=m[l];
			m[r]-=m[l];
			m[l]=0;	
		}
		else
		{
			if(x[l]!=x[r]) h+=m[r];
			m[l]-=m[r];
			m[r]=0;
		}
		if(m[l]==0) l++;
		if(m[r]==0) r--;
		if(l==r||l>r) break;
	}
	printf("%lld",h);
	return 0;
}
