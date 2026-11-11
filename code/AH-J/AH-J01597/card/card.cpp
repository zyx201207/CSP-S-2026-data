#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
map<int,int> q;
map<int,int> q1;
int cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		q[++cnt]=a[i];
		for(int j=i+1;j<=n;j++)
		{
			bool flag=true;
			for(int k=1;k<=cnt;k++)
			{
				if(q[k]==a[j]) 
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				q[++cnt]=a[j];
			}
			else
			{
				for(int k=1;k<=cnt;k++)
				{
					if(q[k]==a[j])
					{
						for(int t=k+1;t<=cnt;t++)
						{
							q[t]=0;
						}
						cnt=k;
						break;
					}
				}
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			q1[q[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<q1[i]<<" ";
	}
	return 0;
}

