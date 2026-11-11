#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5; 
int n,m,zdpos,a[N],ans[M];
bool vis[M];
deque<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]) while(q.size()&&q.back()!=a[j]) vis[q.back()]=0,q.pop_back();
			else q.push_back(a[j]),vis[a[j]]=1;
		}
		while(q.size()) ans[q.back()]++,q.pop_back();
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
