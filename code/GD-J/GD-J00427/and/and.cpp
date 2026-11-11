#include<bits/stdc++.h>
using namespace std;
int a[200001],b[31];
int bz[31];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	b[0]=1;
	for(int i=1;i<=30;i++)
	{
		b[i]=b[i-1]*2;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-m+1;i++)
	{
		int cnt=a[i];
		for(int j=i+1;j<=i+m-1;j++)
		{
			cnt=cnt&a[j];
		}
		memset(bz,0,sizeof(bz));
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}
