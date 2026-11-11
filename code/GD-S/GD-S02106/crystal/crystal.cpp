#include<bits/stdc++.h>
using namespace std;
constexpr int N=5e5+5;
int n;
long long m,a[N];


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	long long sum=0;
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while((i-j)*a[i]-sum>m)sum-=a[j],j++;
		ans=max(ans,i-j+1);
		sum+=a[i];
	}
	printf("%d",ans);
	return 0;
}
