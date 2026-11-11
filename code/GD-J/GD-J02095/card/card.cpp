#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
stack<int> stk;
stack<int> stk2;
int cnt[maxn];
int a[maxn];
check(int x)
{
	bool flag=0;
	while(!stk.empty())
	{
		stk2.push(stk.top());
		if(stk.top()==x)
		{
			flag=1;
		}
		stk.pop();
	}
	while(!stk2.empty())
	{
		stk.push(stk2.top());
		stk2.pop();
	}
	return flag;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(check(a[j]))
			{
				while(!stk.empty())
				{
					if(stk.top()==a[j])
					{
						stk.pop();
						break;
					}
					else
					{
						stk.pop();
					}
				}
				stk.push(a[j]);
			}
			else
			{
				stk.push(a[j]);
			}
		}
		while(!stk.empty())
		{
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
