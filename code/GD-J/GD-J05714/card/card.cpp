#include <bits/stdc++.h>
using namespace std;
long long n,m,p=0;
long long a[5000001],b[500001],c[500001],d[500001];
bool g[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (long long i = 1;i <= n;i ++)
	{
		cin>>a[i];
	}
	long long t=n,o=1;
	while(t--)
	{
		for (long long i = o;i <= n;i ++)
		{
			long long y;
//			for (long long j = 1;j <= p;j ++)
//			{
//				if (b[j]==a[i])
//				{
//					bz=true;
//					y=j;
//					break;
//				}
//			}
			y=d[a[i]];
			if (g[a[i]])
			{
				for (long long j = y;j <= p;j ++)
				{
					g[b[j]]=0;
					d[b[j]]=0;
					b[j]=0;
				}
				p=y-1;
			}
			b[++p]=a[i];
			d[a[i]]=p;
			g[a[i]]=true;
		}
		o++;
		for (long long i = 1;i <= p;i ++)
		{
			c[b[i]]++;
		}
		p=0;
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(g,0,sizeof(g));
	}
	for (long long i = 1;i <= m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

