#include<bits/stdc++.h>
using namespace std;

int c,t,ways;
long long il[3000000];
int s(int u,int v,long long d)
{
	if(il[u+1]-il[u]>d)return 0;
	if(il[v]-il[u]<=d)
	{
		
		return 1;
	}
	for(int i=v;i>=u;i--)
		if(il[i]-il[u]<=d)
		{
			return 1+s(i,v,d); 
			break;
		}
	
			
}
void f(int u,int v,long long d,int dis,int sum)
{
	if(dis==1)return;
	if(sum==dis&&u==v)
	{
		ways++;
		return;
	}
	if(sum==dis)return;
	for(int i=u+1;i<=v;i++)
		if(il[i]-il[u]<=d)
		{
			f(i,v,d,dis,sum+1);
		}
			
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c==11||c==12)
	{
		for(int i=1;i<=t;i++)
		{
			long long n,d;
			cin>>n>>d;
			for(int j=1;j<=n;j++)
				cin>>il[j];
			long long s=d/(il[2]-il[1]);
			long long p=s*2-1;
			if(s==1)
				cout<<0;
			else if(n-p>0)
				cout<<n-p;
			else
				cout<<0;
		}
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			long long n,d,ans=0;
			cin>>n>>d;
			for(int j=1;j<=n;j++)
				cin>>il[j];
			for(int j=1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
				{
					ways=0;
					f(j,k,d,s(j,k,d),0);	
					if(ways==2)
						ans++;
				}		
			cout<<ans<<endl;
		}
	}
}
