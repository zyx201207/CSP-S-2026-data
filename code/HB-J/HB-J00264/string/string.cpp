#include <bits/stdc++.h>
using namespace std;
struct str
{
	long long num;
	char w;
}a[200005];
long long n,k=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) 
	{
		cin>>a[i].num>>a[i].w;
	}
	for(long long i=1;i<=n/2;i++)
	{
		long long k=a[i].num,t=n;
		while(k>a[t].num)
		{
				k-=a[t].num;
				if(a[t].w!=a[i].w) ans+=a[t].num;
				t--;
		}
		if(a[t].w!=a[i].w) ans+=k;
	}
	cout<<ans<<'\n';
	return 0;
}
