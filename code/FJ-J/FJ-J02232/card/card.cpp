#include<bits/stdc++.h>
using namespace std;
int n,m;
struct jj
{
	int ds;
	bool pd;
}a[500010];
int wz[300010];
int ans[300010];
queue<int>q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].ds;
	}
	for(int sss=0;sss<n;sss++)
	{
		int i=1+sss;
		int hhh=n;
		int sl=0;
		for(int hh=i;hh<=n;hh++)
		{
			a[a[hh].ds].pd=false;
		}
		while(i<=hhh)
		{
			if(a[a[i].ds].pd==false)
			{
				q.push(a[i].ds);
				a[a[i].ds].pd=true;
				sl++;
				wz[a[i].ds]=sl;
			}
			else
			{
				int gggggg=sl-wz[a[i].ds]+1;
				for(int k=1;k<=gggggg;k++)
				{
					q.pop();
				}
				q.push(a[i].ds);
				sl-=gggggg;
				wz[a[i].ds]=sl;
			}
			i++;
		}
		int cd=q.size();
		for(int i=1;i<=cd;i++)
		{
			int ghj=q.front();
			q.pop();
			ans[ghj]++;
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
