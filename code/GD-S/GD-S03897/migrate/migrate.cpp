#include<bits/stdc++.h>
using namespace std;
const int e=5e3+10;
int c,t,n,d,a[e],cnt;
struct bid
{
	int tt,ti;
};
bool bfs(int s,int e)
{
	queue<bid>q;
	q.push({0,s});
	int ans=0;
	while(!q.empty())
	{
		bid p=q.front();
		q.pop();
		if(p.ti==e)ans++;
		for(int i=p.ti;i<=e;i++)
		{
			if(a[i]-a[p.ti]>=d)break;
			q.push({i,p.tt+1});
		}
	}
	if(ans==2)return 1;
	else return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int o=0;o<t;o++)
	{
		scanf("%d%d",&n,&d);
		cnt=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(bfs(i,j))cnt++;
			}
		}
	}
	return 0;
}
