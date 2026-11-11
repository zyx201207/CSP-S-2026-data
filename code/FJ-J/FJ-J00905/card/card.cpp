#include<iostream>
#include<stack>
using namespace std;
int ans[300005];
bool f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> pai;
	int n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1)
			{
				while(pai.top()!=a[j])
				{
					f[pai.top()]=0;
					pai.pop();
				}
			}
			else {
			pai.push(a[j]);
			f[a[j]]=1;
		}
		}
		while(!pai.empty())
		{
			ans[pai.top()]++;
			f[pai.top()]=0;
			pai.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0; 
 } 
