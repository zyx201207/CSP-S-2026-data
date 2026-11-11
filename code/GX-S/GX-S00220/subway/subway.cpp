#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,d,w[500010];
long long a[500010][500],iy,iu,ik;
long long mina=INT_MAX,rs,re,zt=INT_MAX,que[500][500],g[500][500],anss=INT_MAX;
bool str[500];
void dfs(int now,int goa,long long used,int st)
{
	if(now==goa)
	{
		if(used+a[rs][st]+a[re][goa]<=mina+zt)
		{
			zt=a[rs][st]+a[re][goa];
			mina=used;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(g[now][i]!=0&&str[i]!=1)
		{
			str[i]=1;
			dfs(i,goa,used+g[now][i],st);
			str[i]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ik;
		for(int j=1;j<=ik;j++)
		{
			cin>>iy>>iu;
			a[iy][i]=iu;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				//cout<<a[i][j]<<" "<<a[i][k]<<endl;
				if(a[i][j]!=0&&a[i][k]!=0)
				{
					if(g[j][k]==0)
					{
						g[j][k]=a[i][j]+a[i][k];
					}else{
						g[j][k]=min(g[j][k],a[i][j]+a[i][k]);
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>rs>>re;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[rs][j]!=0&&a[re][k]!=0)
				{
					if(j==k)
					{
						anss=a[re][k]+a[rs][j];
					}else{
						if(que[j][k]!=0)
						{
							
						}else{
						str[j]=1;
						dfs(j,k,0,j);
						que[j][k]=mina+zt;
						str[j]=0;
					  }
						anss=min(que[j][k],anss);
						mina=INT_MAX;
						zt=INT_MAX;
					}
				}
			}
		}
		//cout<<mina<<" "<<zt<<endl;
		cout<<w[rs]+anss+w[re]<<endl;
		anss=INT_MAX;
	}
	return 0;
}
