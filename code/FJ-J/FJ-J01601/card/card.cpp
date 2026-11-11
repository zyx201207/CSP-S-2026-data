#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
bool f[500005];
stack <int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		while(!st.empty())
		{
			st.pop();
		}
		for(j=i;j<=n;j++)
		{
			if(!f[a[j]])
			{
				st.push(a[j]);
				f[a[j]]=1;
			}
			else
			{
				while(!st.empty()&&st.top()!=a[j])
				{
					int to=st.top();
					f[to]=0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			int to=st.top();
			//cout<<to<<endl;
			if(f[to])
			{
				ans[to]++;
				f[to]=0;
			}
			st.pop();
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
