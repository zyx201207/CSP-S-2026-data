#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][505],t[505][505],x[500005],y[500005],ch[500005][505];
int solve(int a,int b)
{
	int sum=w[a]+w[b],r;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ch[a][i]&&ch[j][i])
			{
				sum+=t[i][a]+solve(j,b);
				r=i;	
			} 
		}
	}
	sum+=t[r][b];
	return sum;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool flag=true,f=true;
	memset(ch,0,sizeof(ch));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2) flag=false;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			ch[a[i][j]][i]=1;
			if(t[i][j]!=t[1][1]) f=false;
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	if(n<=2)
	{
		for(int i=1;i<=q;i++)
		{
			if(n==1||(a[x[i]][1]&&a[y[i]][1])||(a[x[i]][2]&&a[y[i]][2]))
			{
				if(ch[x[i]][1]==1) cout<<w[x[i]]+w[y[i]]+t[x[i]][1]+t[y[i]][1]<<endl;
				else cout<<w[x[i]]+w[y[i]]+t[x[i]][2]+t[y[i]][2]<<endl; 
			}
		}
	}
	else
	{
		int minn=1e9;
		for(int i=1;i<=m;i++)
		{
			if(ch[i][1]&&ch[i][2]) minn=min(minn,t[i][1]+t[i][2]);
		} 
		for(int i=1;i<=q;i++)
		{
			if(ch[x[i]][1]==1) cout<<w[x[i]]+w[y[i]]+t[x[i]][1]+t[y[i]][2]+minn<<endl;
			else cout<<w[x[i]]+w[y[i]]+t[x[i]][2]+t[y[i]][1]+minn<<endl;
		} 
	}
	if(f==true)
	{
		for(int i=1;i<=q;i++)
		{
			int g=0,sum1,sum2,tmp;
			for(int i=1;i<=n;i++)
			{
				if(ch[x[i]][i]) sum1=i;
				if(ch[y[i]][i]) sum2=i;
				if(ch[x[i]][i]==ch[y[i]][i]) 
				{
					g=1;
					tmp=i;
				}
			}
			if(g) cout<<w[x[i]]+w[y[i]]+t[x[i]][tmp]+t[y[i]][tmp]<<endl;
			else 
			{
				cout<<w[x[i]]+w[y[i]]+t[x[i]][sum1]+t[y[i]][sum2]+2*t[1][1]<<endl;
			}
		}
	}
	if(flag==true||(n<=50&&m<=300&&d<=20&&q<200))
	{
		for(int i=1;i<=q;i++)
		{
			cout<<solve(x[i],y[i])<<endl;
		}
	}
	return 0;
}
