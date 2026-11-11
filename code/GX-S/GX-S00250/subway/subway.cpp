#include<bits/stdc++.h>
using namespace std;
int a[510][500010],b[500010],v[500010],v1[510];
int c,n,m,d,q,ans,a1=0;
int found(int x,int y,int l)
{
	if(x==y)
	{
	   ans=min(ans,a1);
	   return 0;
	}
	else
	{
			for(int i=1;i<=n;i++)
			{
				if(a[i][x]>0&&v1[i]==0)
				{
					a1+=a[i][x];
					v1[i]=1;
					found(x,y,i);
					v1[i]=0;
					a1-=a[i][x];
				}
			}		
			for(int j=1;j<=m;j++)
			{
				if(a[l][j]>0&&v[j]==0)
				{
					v[j]=1; a1+=a[l][j];
					found(j,y,l);
					v[j]=0; a1-=a[l][j];
				}
			}
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(a,0,sizeof(n*m));
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a1,b1;
			scanf("%d%d",&a1,&b1);
			a[i][a1]=b1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y; ans=1e5;
		scanf("%d%d",&x,&y);
		a1=b[x]+b[y];
		memset(v,0,sizeof(m));
		memset(v1,0,sizeof(n));
		found(x,y,0);
		cout<<ans<<endl;
	}
	return 0;
}
	 
