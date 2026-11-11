#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N=500000;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,ans,j;
	long long m,s;
	scanf("%d%lld",&n,&m);
	for (i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	s=0;
	ans=0;
	for (i=j=0;i<n;i++)
	{
		for (s+=a[i];a[i]*(i-j+1)-s>m;s-=a[j++]);
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
