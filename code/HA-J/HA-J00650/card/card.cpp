#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int num[1000010];
int lst[1000010];
int vis[1000010];
int n,m,ans[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);queue<int> ppp;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) num[a[i]]++,lst[a[i]]=i;
	for(int i=1;i<=m;i++) if(a[lst[i]+1]!=0) vis[a[lst[i]+1]]++;
	for(int i=1;i<=m;i++) if(!vis[i]) ppp.push(i);
	for(int i=1;i<=m;i++) ans[i]=num[i];
	while(ppp.size())
	{
		int u=ppp.front();ppp.pop();
		ans[a[lst[u]+1]]+=ans[u];
		if((--vis[a[lst[u]+1]])==0) 
		{
			ppp.push(a[lst[u]+1]);
		}
	}
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	ans[1]++;ans[1]--;
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
