#include<bits/stdc++.h>
using namespace std;
#define N 200010
int a[N],tot[30];
bool v[N],cnt[N][30];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int x=a[i];
		for(int j=29;j>=0;j--)
		{
			if(x>=(1<<j))
			{
				x-=(1<<j);
				cnt[i][j]=1;
				tot[j]++;
			}
			if(x==0)break;
		}
	}
	int ans=0;
	for(int i=29;i>=0;i--)
	{
		if(tot[i]>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(!v[j]&&!cnt[j][i])
				{
					v[j]=1;
					for(int k=0;k<30;k++)
					{
						if(cnt[j][k])tot[k]--;
					}
				}
			}
			ans+=(1<<i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
