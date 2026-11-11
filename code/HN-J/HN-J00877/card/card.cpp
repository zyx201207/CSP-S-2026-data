#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int num[300030];
bool dis[300030];
stack<int> stk;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(dis,0,sizeof(dis));
		for(int j=i;j<=n;j++)
		{
			if(dis[a[j]])
			{
				while(stk.top()!=a[j])
					dis[stk.top()]=0,stk.pop();
				stk.pop(),dis[a[j]]=0;
			}
			stk.push(a[j]),dis[a[j]]=1;
		}
		while(!stk.empty())
		{
			num[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<" ";
	return 0;
}
