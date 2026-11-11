#include<bits/stdc++.h> 
using namespace std;
long long e[2000050],dd[2000050],o,ww[2501][2501],b[2501][2501],a[2000050],d[2501][2501],w,c,t,n,tt;
void dfs(int l,int r,int an)
{
	e[r]=1;
	if(b[l][r]>an)
	{
		b[l][r]=an;
		w=1;
		ww[l][r]=w;
	}
	if(b[l][r]==an)
	{
		w++;
		ww[l][r]=w;
	}
	for(int i=1;i<=n;i++)
	{
		if(!d[i]&&d[r][i]<=tt)
		{
			dfs(l,i,an+d[r][i]);
		}
	}
	e[r]=0;
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	memset(b,0x3f3f3f3f,sizeof(b));
	while(t)
	{
		t--;
		w=0,o=0;
		cin>>n>>tt;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			d[i][(i+1)%n]=d[(i+1)%2][i]=a[i];
			dd[i]=dd[i-1]+a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(abs(i-j)!=1&&i!=j)
				{
					d[i][j]=d[j][i]=abs(dd[j]-dd[i]);
				}
				if(i==j)d[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			dfs(i,i,a[i]);
			ww[i][i]=0;
		}
		w=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(ww[i][j]==2)w++;
			}
		}
		cout<<w<<endl;
	}
	return 0;
}
