#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

struct node
{
	int num;
	int val;
}p[N]; 

int n,m;
bool vis[N];
stack<node> st;
int ans=0;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i].val);
	}
	for(int k=1;k<=m;k++)
	{
		ans=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=i;j++)
			{
				vis[p[j].val]=false;
			}
			for(int j=n;j>=i;j--)
			{
				vis[p[j].val]=true;
				st.push({j,p[i].val});
			}
			for(int j=1;j<=i;j++)
			{
				if(vis[j])
				{
					while(st.top().val!=p[j].val)
					{
						vis[st.top().val]=false;
						st.pop();
					}
				}
				else
				{
					st.push({j,p[j].val});
				}
			}
			if(vis[i]==true)
			{
				ans++;
			}
		}
		printf("%d ",ans);
	}
}
