#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
const long long M=3e5+10;
long long n,m;
long long a[N];
long long b[N];
long long ans[M];
long long o[N];
void solve(long long w)
{
	long long cnt=0;
	for(long long i=w;i<=n;i++)
	{
		if(b[a[i]]>cnt||o[b[a[i]]]!=a[i])
		{
			cnt++;
			o[cnt]=a[i];
			b[a[i]]=cnt;
		}
		else
		{
			cnt=b[a[i]];
		}
	}
	for(long long i=1;i<=cnt;i++)
	{
		ans[o[i]]++;
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		solve(i);
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
