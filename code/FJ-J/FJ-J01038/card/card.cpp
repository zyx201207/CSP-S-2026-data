#include<bits/stdc++.h>
using namespace std;
int a[5001],i,j,k,ans[5001],n,m,yes[5001];
stack<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		memset(yes,0,sizeof(yes));
		for(j=i;j<=n;j++)
		{
			if(yes[a[j]]==0)
			{
				s.push(a[j]);
				yes[a[j]]=1;
			}else{
				while(s.size()&&s.top()!=a[j])
				{
					yes[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
