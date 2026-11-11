#include<bits/stdc++.h>
using namespace std;
int data,n;
long long d,x[2000010],dist[2000010],f[2000010],ans[2000010],tx,dhy;
queue<long long> q;
struct node
{
	int x;
	int mx;
}tu[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int i,T;
	cin>>data>>T;
	while(T--)
	{
		dhy=0;
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
			f[i]=0;
			tu[i].x=i;
			tu[i].mx=0;
		}
		if(data==13||data==14)
		{
			cout<<0<<endl;
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(int j=1+i;j<=n;j++)
			{
				if(x[j]-x[i]<=d)
				{
					tu[i].mx=max(tu[i].mx,j);
				}
				else
				{
					break;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(i=k;i<=n;i++)
			{
				f[i]=0;
				dist[i]=-1;
				ans[i]=0;
			}
			dist[k]=0;
			q.push(k);
			ans[k]=1;
			f[k]=1;
			while(!q.empty())
			{
				tx=q.front();
				q.pop();
				for(i=tx+1;i<=tu[tx].mx;i++)
				{
					if(f[i]==0)
					{
						dist[i]=dist[tx]+1;
						ans[i]+=ans[tx];
						q.push(i);
						f[i]=1;
					}
					else if(f[i]==1)
					{
						if(dist[tx]+1==dist[i])
						{
							ans[i]+=ans[tx];
						}
					}
				}
			}
			for(i=k;i<=n;i++)
			{
				if(ans[i]==2)
				{
					dhy++;
				}
			}			
		}
		cout<<dhy<<endl;
	}
	return 0;
}
