#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[16384],sum,maxn=INT_MIN;
signed main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		a[i]++;
		m--;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]==a[i])
				++sum;
			else if(a[j]<a[i])
			{
				a[j]++;
				m--;
				sum++;
			}
			if(!m)	break;
		}
		maxn=max(maxn,sum);
	}
	printf("%d",maxn);
	return 0;
}