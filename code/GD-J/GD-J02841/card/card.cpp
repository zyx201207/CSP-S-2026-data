#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5*100000+5],b[3*100000+5],a1145=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(a1145<=n)
	{
		long long bb[m+5];
		for(int i=0;i<=m;i++) bb[i]=0;
		for(int i=a1145;i<=n;i++)
		{
			if(bb[a[i]]!=0)
			{
				for(int j=bb[a[i]];j<=i;j++)
				{
					bb[a[j]]=0;
				}
				bb[a[i]]=i;
			}
			else
			{
				bb[a[i]]=i;
			}
		}
		for(int i=0;i<=m;i++) if(bb[i]!=0) b[i]++;
		a1145++;
	}
	for(int i=1;i<=m;i++) printf("%lld ",b[i]);
	return 0;
}
