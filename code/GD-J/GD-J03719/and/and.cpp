#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=-100000;
bool visit[200010];
void dfs(int c)
{
	int i,temp,temp2;
	if(c==m)
	{
		for(i=1;i<=n;i++)
			if(visit[i]==true)
			{
				temp=a[i];
				temp2=i;
				break;
			}
		for(i=1;i<=n;i++)
			if(visit[i]==true&&i!=temp2)
				temp=temp&a[i];
		if(temp>ans)
			ans=temp;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(visit[i]==false)
		{
			visit[i]=true;
			dfs(c+1);
			visit[i]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(i=1;i<=n;i++)
			if(a[i]>ans)
				ans=a[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
