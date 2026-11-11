#include<bits/stdc++.h>
using namespace std;
struct card
{
	int id,num;
}a[500002],c[500002];
int n,m,b[300002],ans[300002];
int find(int c,int q)
{
	for(int i=c;i<=n;i++)
	{
		if(a[i].num==q)return a[i].id;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num;
		b[a[i].num]++;
		a[i].id=i;
		c[i].num=a[i].num;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j].num=c[j].num;
		}
		for(int j=i;j<=n;j++)
		{
			for(int l=1;l<=m;l++)
			{
				if(b[l]>=2)
				{
					if(a[j].num==l)
					{
						for(int k=a[j].id+1;k<=find(a[j].id+1,i);k++)
						{
							a[k].num=-1;
						}
					}
					for(int s=1;s<=n;s++)cout<<a[s].num<<" "; 
				}
				else
				{
					continue;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j].num!=-1)ans[a[j].num]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
} 
