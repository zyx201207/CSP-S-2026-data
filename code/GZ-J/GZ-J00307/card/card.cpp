/*
	准考证号：GZ-J00307
	学校：华麟学校
	姓名：刘凌睿 
*/
#include<bits/stdc++.h>
using namespace std;
int a[500005],last[300005],t[500005],num[300005];
vector<pair<int,int> > vis(500005);
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int n1=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(n1--)
	{
		int start=n-n1;
		int size=0,times=0;
		for(int i=start;i<=n;i++)
		{
			if(t[a[i]]+1==1)
			{
				t[a[i]]++;
				last[a[i]]=i;
			}
			else
			{
				vis.push_back({last[a[i]],size});
				times++;
			}
			size++;
		}
		for(int i=1;i<=times;i++)
		{
			int v=vis[i].first,w=vis[i].second;
			for(int j=start;j<=n;j++)
			{
				if(j<v||j>v+w-1)
				{
					num[a[j]]++;
				}
			}
		}
		for(int i=1;i<=times;i++)
		{
			vis[i]={0,0};
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<" ";
	}
	return 0;
}
