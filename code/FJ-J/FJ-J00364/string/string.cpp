#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
long long cnt=0,jj=1;
char c[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		cnt+=x;
		char a;
		cin>>a;
		for (long long j=jj;j<=cnt;j++) c[j]=a;
		jj=cnt;
	}
	for (int i=1;i<=cnt/2+1;i++)
	{
		if (c[i]!=c[cnt-i+1])
		{
			ans++;
			c[n-i+1]=c[i];
		} 
	}
	cout<<ans;
	return 0;
}

