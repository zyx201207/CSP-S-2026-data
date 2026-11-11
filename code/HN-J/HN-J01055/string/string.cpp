#include <bits/stdc++.h>
using namespace std;
string b;
long long a[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,h;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			sum+=min(a[i],a[n-i+1]);
			if(max(a[i],a[n-i+1])-min(a[i],a[n-i+1])>0)
				n++;
		}
	}
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
