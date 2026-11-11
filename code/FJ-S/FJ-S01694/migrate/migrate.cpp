#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t,n,d,x[N],to[10],ans;
void dfs(long long u,long long v,long long s)
{
	if(u==v)
	{
		to[s]++;
		return;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(x[i]-x[u]>d) continue;
		dfs(i,v,s+1);
	}
} 
int main()
{   
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		for(int i=1;i<n;i++)
		{   
			for(int k=i+1;k<=n;k++)
			{    
			    memset(to,0,sizeof(to));
			    dfs(i,k,0);
			    for(int j=1;j<=n;j++)
		        {
			        if(to[j]>0)
			        {
				       if(to[j]==2) ans++;
	                   break;
			        }
		        }
			}
		}
		cout<<ans<<endl;
	}
}
