#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q;
long long int w[1010000];
long long int tim,e,f,ss,sss=INT_MAX;
struct book{
	long long int k;
	long long int num[100],t[100];
}a[1000];
long long int r[1010000][2];
long long int z[1000][100];
long long int dps(long long int x,long long int y,long long int s)
{
	s=s+a[x].t[y];
	z[x][y]=s;
	for(int l=1;l<=a[x].k;l++)
	{
		if(l==y)
		{
			continue;
		}
		else if(a[x].num[l]==f)
		{
			if(z[x][l]==-1||s+a[x].t[l]<z[x][l])
			{
				z[x][l]=s+a[x].t[l];
				ss=z[x][l];
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=a[i].k;j++)
				{
					if(a[i].num[j]==a[x].num[l]&&i!=x)
					{
						if(z[i][j]==-1||s+a[x].t[l]+a[i].t[j]<z[i][j])
						{
							dps(i,j,s+a[x].t[l]);
						}
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++)
		{
			cin>>a[i].num[j]>>a[i].t[j];
		}
	}
	for(int l=1;l<=q;l++)
	{
		sss=INT_MAX;
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=100;j++)
			{
				z[i][j]=-1;
			}
		}
		cin>>r[l][0]>>r[l][1];
		e=r[l][0];
		f=r[l][1];
		tim=w[e]+w[f];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].k;j++)
			{
				if(a[i].num[j]==e)
				{
					dps(i,j,0);
					if(ss<sss)
					{
						sss=ss;
					}
				}
			}
		}
		cout<<sss+tim<<endl;;
	}
	return 0;
}
