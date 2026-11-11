#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool v[300005];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i;i<=n;j++)
		{
			if(v[a[j]]==0)
			{
				s.push(a[j]);
				v[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					v[s.top()]=0;
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
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
