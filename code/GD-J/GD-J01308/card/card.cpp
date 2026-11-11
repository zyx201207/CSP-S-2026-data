#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[500005],b[300005],pos[300005],ans[300005],n,m,top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(pos[a[j]]>0)
			{
				int be=pos[a[j]];
				int you=top;
				top=be-1;
				while(be<=you)
				{
					pos[b[be]]=0;
					b[be]=0;
					be++;
				}
			}
			b[++top]=a[j];
			pos[a[j]]=top;
		}
		for(int j = 1; j <= m; j++)
			if(pos[j]>0)
				ans[j]++;
		memset(b,0,sizeof(b));
		memset(pos,0,sizeof(pos));
	}
	for(int i = 1; i <= m; i++)
		cout<<ans[i]<<' ';
	return 0;
}
