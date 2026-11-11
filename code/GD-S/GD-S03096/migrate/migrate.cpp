#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c,t,n,m,ans,skip[2000002];
ll d,x[2000002];
int cutdfs(int u,int v,int minl,int tokenl)
{
	if(u==v) return 1;
	if(tokenl>=minl) return 0;
	int sum=0;
	for(int i=1;i<=skip[u];i++)
	{
		sum+=cutdfs(u+i,v,minl,tokenl+1);
	}
	return sum;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		int edge=0;
		while(edge<n)
		{	
			int head=edge+1;
			edge=n;
			for(int i=head;i<=edge;i++)
			{
				for(int j=i+1;j<=edge;j++)
				{
					if(j==edge) skip[i]=j-i;
					if(x[j]-x[j-1]>d) edge=j-1,skip[i]=j-1-i;
					if(x[j]-x[i]>d) 
					{
						skip[i]=j-i-1;
						break;
					}
				}
				
			}
			//for(int i=head;i<=edge;i++) printf("%d ",skip[i]);
			int minl=0;
			for(int i=head;i<edge;i+=skip[i])
			{
				minl++;
			}
			
			for(int i=edge;i>=head+3;i--)
			{
				int xp=cutdfs(head,i,minl,0);
				if(xp==2) ans++;	
			}
			
			
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
