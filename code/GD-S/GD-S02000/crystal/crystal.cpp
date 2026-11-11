#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10; 
long long n,m;
long long a[N];
long long b[N];
long long maxx=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];	
	} 
	sort(a+1,a+n+1);
	long long l=1;
	for (int i=1;i<=n;i++)
	{
		while ((i-l)*b[i]-b[i-1]-b[l-1]>m && l<=n)
		{
			l++;
		}
		long long bam=i-l+1;
		maxx=max(maxx,bam);
	}
	cout<<maxx;
	return 0;
}
