#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int a[N];
int st[N],len;
int ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=30;i>=0;i--)
	{
		len=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]&(1<<i))
			{
				st[++len]=a[j];
			}
		}
		if(len>=m)
		{
			ans+=(1<<i);
			n=len;
			for(int i=1;i<=len;i++)
			{
				a[i]=st[i];
			}
		}
	}
	printf("%d",ans);
	return 0;
}

