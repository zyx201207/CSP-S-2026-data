#include<bits/stdc++.h>
using namespace std;
struct node
{
	int visited;
	int pos;
}v[500005];
int sum[500005],a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=500000;j++)
		{
			v[j].visited=0;
			v[j].pos=0;
		}
		if(i==n)sum[a[i]]++;
		queue<int>card;
		card.push(a[i]);
		v[a[i]].visited=1;
		v[a[i]].pos=1;
		for(int j=i+1;j<=n;j++)
		{
			if(v[a[j]].visited==0)
			{
				card.push(a[j]);
				v[a[j]].visited=1;
				v[a[j]].pos=j;
				
			}
			else
			{
				for(int k=1;k<v[a[j]].pos;k++)
				{
					int w=card.front();
					card.push(w);
				}
				for(int k=v[a[j]].pos;k<=j-1;k++)
				{
					card.pop();
				}
				card.push(a[j]);
				v[a[j]].visited=1;
				v[a[j]].pos=j;
        	}
			if(j==n)
			{
				while(!card.empty())
				{
					int k=card.front();
					card.pop();
					sum[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<' ';
	}
}
