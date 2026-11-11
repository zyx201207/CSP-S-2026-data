#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,k=0,f[200005];
vector<int>b[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=30;j>=0;j--)
		{
			if((a[i]>>j)&1)
			{
				b[j].push_back(i);
			}
		}
	}
	for(int i=30;i>=0;i--)
	{
		if((int)(b[i].size())>=m)
		{
			int h=0;
			for(int j=0;j<(int)(b[i].size());j++)
			{
				if(f[b[i][j]]==k)h++;
			}
			if(h>=m)
			{
				for(int j=0;j<(int)(b[i].size());j++)
				{
					if(f[b[i][j]]==k)
					{
						f[b[i][j]]++;
					}
				}
				k++;
			}
		}
	}
	ans=(1<<30)-1;
	for(int i=1;i<=n;i++)
	{
		if(f[i]==k)
		{
			ans=(ans&a[i]);
		}
	}
	printf("%d",ans);
	
	return 0;
}
