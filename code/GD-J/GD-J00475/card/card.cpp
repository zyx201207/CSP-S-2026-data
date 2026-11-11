#include<cstdio>
#include<stack> 
#include<algorithm>
using namespace std; 
using ll=long long;
const int maxn=5e5+5,maxm=3e5+5;
int a[maxn],ans[maxm];
int n, m;
stack<int>que;
bool flag[maxm];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++) flag[i]=0;
		
		for(int i=k;i<=n;i++)
		{

			if(flag[a[i]]==0)
			{
				flag[a[i]]=1;
				que.push(a[i]);
			}
			else
			{
				while(que.top()!=a[i])
				{
					int x=que.top();
					flag[x]=0;
					que.pop();
				}
			}
		}
		
		while(!que.empty())
		{
			ans[que.top()]++;
			que.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}


