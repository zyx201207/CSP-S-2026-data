//GZ-J00003 ¶­ÜÇÐù 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000001];
long long cnt[1000001],cnts[1000001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	bool q=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i+1])
		{
			q=1;
		}
	}
	if(q==0)
	{
		for(int i=1;i<=n;i++)
		{
			cnts[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			cnts[i]++;
		}
		for(int i=1;i<=m;i++)
		{
			cnts[i]+=cnts[i-1];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<cnts[i]<<' ';
		}
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> stk;
		bool o[201];
		for(int i=1;i<=200;i++)
		{
			o[i]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(o[a[j]]==1)
			{
				while(stk.top()!=a[j])
				{
					o[stk.top()]=0;
					stk.pop();	
				}
			}
			else
			{
				stk.push(a[j]);
				o[a[j]]=1;
			}
		}
		while(stk.size()!=0)
		{
			cnt[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
