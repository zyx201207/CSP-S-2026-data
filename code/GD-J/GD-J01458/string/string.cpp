#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
struct node
{
	int x,k;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	int m=0;
	for(int i=1;i<=n;i++)
	{
		char op[2];
		scanf("%lld%s",&a[i].k,op);
		a[i].x=op[0]-'a'+1;
		m+=a[i].k;
	}
	int i=1,j=n,sum=0,ans=0;
	while(1)
	{
		if(sum+a[i].k>=m/2)
		{
			while(j!=i)
			{
				if(a[j].x!=a[i].x)
				{
					ans+=a[j].k;
				}
				j--;
			}
			break;
		}
		sum+=a[i].k;
		while(a[j].k<a[i].k)
		{
			if(a[j].x!=a[i].x)
			{
				ans+=a[j].k;
			}
			a[i].k-=a[j].k;
			j--;
		}
		if(a[i].x!=a[j].x)
		{
			ans+=a[i].k;
		}
		a[j].k-=a[i].k;
		i++;
	}
	printf("%lld\n",ans);
	return 0;
}
