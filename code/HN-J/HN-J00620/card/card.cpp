#include<iostream>
#include<stack>
using namespace std;
int n,m; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int sum[m+10]={0},b[n+10]={0},flag[m+10]={0};


	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int j=1;j<=n;j++)
	{
		stack<int> s;
		for(int i=j;i<=n;i++)
		{
			s.push(b[i]);
			if(!flag[s.top()])
			{
				flag[s.top()]=1;
			}
			else
			{
				while(s.top()!=b[i])
				{
					s.pop();
				}
				flag[s.top()]=0;
			}
		}
		while(!s.empty())
		{
			sum[s.top()]++;
			s.pop();
		}
	}

	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}
