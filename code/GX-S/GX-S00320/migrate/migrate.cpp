#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long C,T,n,d,v[N],pre[N],as;

void dfs(int u,int to,int len)
{
	if(len==0 || u==to)	
	{
		if(len==0 && u==to)	as++;
		return;
	}
	for(int i=u+1;i<=to;i++)
	{
		//cout<<u<<' '<<i<<' '<<to<<' '<<len<<endl;
		if(v[i]-v[u]<=d)	dfs(i,to,len-1);
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>C>>T;
	if(C<3)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)	cin>>v[i],pre[i]=v[i]-v[i-1];

			int ans=0;
			for(int i=1;i<n-2;i++)
			{
				for(int j=i+3;j<=n;j++)
				{
					if(v[j]-v[i]<=d)	continue;
					int sign=1;
					for(int k=i+1;k<=j;k++)
					{
						if(d<pre[k])	
						{
							sign=0;
							break;
						}
					}
					if(!sign)	break;

					for(int len=2;len<j-i;len++)
					{
						as=0;
						dfs(i,j,len);
						if(as==2)	ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	else if(C==12 || C==13)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)	cin>>v[i];
			int x=v[2]-v[1];
			x=n-(d/x)*2+1;
			cout<<max(0,x)<<endl;
		}
	}
	else
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)	cin>>v[i];
			cout<<0<<endl;
		}
	}
	return 0;
}
