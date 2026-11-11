#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

int n,m,cn,a[500005],b[300005],cache[500005];

inline void llet(int k)
{
	for(ll i=k+1;i<=cn;++i)
	{
		cache[i]=0;
	}
	cn=k;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	cn=n;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		llet(cache);
		for(int j=i;j<=n;++j)
		{
			bool flag=true;
			for(int k=cn;k>=1;--k)
			{
				if(cache[k]==a[j])
				{
					llet(k);
					flag=false;
					break;
				}
			}
			if(flag)
			{
				cache[++cn]=a[j];
			}
		}
		for(int j=1;j<=cn;++j)
		{
			++b[cache[j]];
		}
		memset(cache,0, sizeof(cache));
	}
	for(ll i=1;i<=m;++i)
	{
		printf("%d ",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
