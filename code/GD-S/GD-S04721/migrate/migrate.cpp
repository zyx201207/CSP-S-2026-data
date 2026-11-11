#include<bits/stdc++.h>
using namespace std;
int c,T,n,f[305][305];
long long x[2000005],l;
unsigned long long d;
vector<int>g[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		if(c<6) memset(f,0x3f3f3f,sizeof(f));
		l=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			for(int j=1;j<i;j++)
			{
				//if((unsigned long long)x[i]-x[j]<=d) g[j].push_back(i);
				if((unsigned long long)x[i]-x[j]<=d && c<=6) f[j][i]=1;
			}
		}
		if(c<=6)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j) continue;
					int p=0;
					for(int k=1;k<=n;k++)
					{
						if(k==i || k==j) continue;
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
					for(int k=1;k<=n;k++)
					{
						if(k==i || k==j) continue;
						if(f[i][j]==f[i][k]+f[k][j]) p++;
					}
					if(p==2 && i<j) l++;
				}
			}
			printf("%lld\n",l);
		}
		else if(c>=13 && c<=14)
		{
			int t1=-1;
			for(int i=1;i<=n;i++)
			{
				if((unsigned long long)x[i]-x[1]<=d && (unsigned long long)x[n]-x[i]<=d) 
				{
					t1=i;
					break;
				}
			}
			for(int i=max(1,t1-3);i<t1;i++)
			{
				if((unsigned long long)x[i+2]-x[i]>d && (unsigned long long)x[i+3]-x[i+1]>d) l++;
			}
			printf("%lld\n",l);
		}
	}
	return 0;
}

