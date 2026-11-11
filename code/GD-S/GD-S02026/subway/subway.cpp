#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=2e3+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int c,n,m,d,q;
int ex[N];
int tmp[30];
int tmpp[30];
map<PII,int>edge; 
map<PII,int>dist;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();
	n=in();
	m=in();
	d=in();
	q=in();
	for(int i=1;i<=m;i++)
	{
		ex[i]=in();
	}
	for(int i=1;i<=n;i++)
	{
		int k=in();
		for(int j=1;j<=k;j++)
		{
			tmp[j]=in();
			tmpp[j]=in();
		}
		for(int j=1;j<=k;j++)
		{
			for(int jj=j+1;jj<=k;jj++)
			{
				int xx=tmp[j],yy=tmp[jj];
				if(edge.count({xx,yy}))
				{
					edge[{xx,yy}]=min(edge[{xx,yy}],tmpp[j]+tmpp[jj]);
					edge[{yy,xx}]=min(edge[{yy,xx}],tmpp[j]+tmpp[jj]);
					dist[{xx,yy}]=min(dist[{xx,yy}],tmpp[j]+tmpp[jj]);
					dist[{yy,xx}]=min(dist[{yy,xx}],tmpp[j]+tmpp[jj]);
				}
				else
				{
					edge[{xx,yy}]=tmpp[j]+tmpp[jj];
					edge[{yy,xx}]=tmpp[j]+tmpp[jj];
					dist[{xx,yy}]=edge[{xx,yy}];
					dist[{yy,xx}]=edge[{yy,xx}];
				}
			}
		}
	}
	for(int mid=1;mid<=m;mid++)
	{
		for(int xx=1;xx<=m;xx++)
		{
			for(int yy=1;yy<=m;yy++)
			{
				if(mid!=xx&&mid!=yy&&xx!=yy)
				{
					if(dist.count({xx,mid})&&dist.count({yy,mid}))
					{
						if(!dist.count({xx,yy}))
						{
							dist[{xx,yy}]=dist[{xx,mid}]+dist[{yy,mid}];
							dist[{yy,xx}]=dist[{xx,yy}];
						}
						else
						{
							dist[{xx,yy}]=min(dist[{xx,yy}],dist[{xx,mid}]+dist[{yy,mid}]);
							dist[{yy,xx}]=dist[{xx,yy}];
						}
					}	
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int xx=in(),yy=in();
		out(ex[xx]+ex[yy]+dist[{xx,yy}]);
		cout<<endl;
	}
	return 0;
}

