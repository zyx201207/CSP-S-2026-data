#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],l[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		vector <int> v;
		memset(l,0,sizeof(l));
		for(int j=i;j<=n;j++)
		{
			//printf("%d %d %d %d\n",i,j,a[j],l[a[j]]);
			if(l[a[j]])
			{
				int times=v.size()-l[a[j]];
				for(int k=1;k<=times;k++)
				{
					if(l[v.back()]==v.size())l[v.back()]=0;
					v.pop_back();
				}
				//printf("%d\n",v.back());
			}
			else
			{
				l[a[j]]=v.size()+1;
				v.push_back(a[j]);
			}
		}
		for(int j=0;j<v.size();j++)ans[v[j]]++;
		//for(int j=0;j<v.size();j++)printf("%d ",v[j]);
		//puts("");
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
