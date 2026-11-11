#include<bits/stdc++.h>
using namespace std;
long long x[5005];
long long cnt;
long long n,d;
void dfs(long long node,long long num,long long en,long long tag)
{
	if(num>tag)return;
	if(node>en)return;
	if(node==en&&num==tag)
	{
		cnt++;
		return;
	}
	for(long long i=node+1;i<=en;i++)
	{
		if(x[i]-x[node]>d)return;
		dfs(i,num+1,en,tag);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>x[i];
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				long long node=i;
				long long num=0;
				while(node!=j)
				{
					long long temp=node;
					while(x[temp]-x[node]<=d)temp++;
					temp--;
					if(temp==node)
					{
						num=-1;
						break;
					}
					node=temp;
					num++;
					if(node>j)node=j;
				}
				cnt=0;
				dfs(i,0,j,num);
				if(cnt==2)ans++;
//				cout<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
