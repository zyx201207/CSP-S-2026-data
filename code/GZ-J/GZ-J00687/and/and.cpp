//贵阳中天中学裴天元GZ-J00687
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],cnt=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		int count=0;
		for (long long j=1;count<31;count++,j*=2)
		{
			if (a[i]==j-1)b[++cnt]=a[i];
		}
	}
	sort(b+1,b+cnt+1);
	sort(a+1,a+n+1);
	long long ans=b[cnt];m--;
	for (int i=cnt-1;i>0 and --m>=1;i--)
	{
		ans&=b[i];
	}
	m++;
	for (int i=n;i>0 and m>=0;i--,m--)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
