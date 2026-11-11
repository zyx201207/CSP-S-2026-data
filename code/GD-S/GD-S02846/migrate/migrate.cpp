#include<cstdio>
long long x[2000010],dt[2000010];
int jp[310][310];
int main()
{
	freopen("migrate3.in","r",stdin);
	freopen("migrate3.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c==11||c==12)
	{
		while(t--)
		{
			int n;
			long long d;
			scanf("%d%lld",&n,&d);
			if(n<=2)
			{
				puts("0");
				for(int i=1;i<=n;i++)scanf("%lld",&d);
				continue;
			}
			long long x1,x2,jl;
			scanf("%lld%lld",&x1,&x2);
			jl=x2-x1;
			while(getchar()!='\n');
			if(d<jl*2||n-(d/jl)*2+1<0)puts("0");
			else printf("%lld\n",n-(d/jl)*2+1);
		}
		return 0;
	}
	/*if(c<0)
	{
		while(t--)
		{
			int n;
			long long d;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			for(int i=1;i<n;i++)
			{
				int lt=i;
				for(int j=i+1;j<=n;j++)
				{
					if(x[j]-x[lt]<=d)jp[i][j]=jp[i][lt]+1;
					else
					{
						if(x[j]-x[j-1]>d)
						{
							for(;j<=n;j++)jp[i][j]=-1;
							break;
						}
						else
						{
							lt=j-1;
							jp[i][j]=jp[i][j-1]+1;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					if(jp[i][j]==-1)break;
					int cnt=0;
					for(int k=i+1;k<j;k++)
					{
						if(jp[i][k]+jp[k][j]==jp[i][j])cnt++;
					}
					if(cnt==1)ans++;
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}*/
	while(t--)
	{
		int n;
		long long d;
		scanf("%d%lld%lld",&n,&d,&x[1]);
		int now=1;
		for(int i=2;i<=n;i++)
		{
			scanf("%lld",&x[i]),dt[now]=x[i]-x[i-1];
			if(dt[now]+dt[now-1]<d)dt[i-1]+=dt[i-2];
		}
		long long ans=0;
		bool qf=false;
		int lt=0,rt=0;
		dt[n]=d+1;
		for(int i=3;i<n;i++)
		{
			if(dt[i]+dt[i-1]<=d&&dt[i-1]+dt[i-2]<=d&&dt[i]+dt[i-1]+dt[i-2]>d)
			{
				qf=true;
				ans+=(lt+1)*(rt+1);
				lt=rt;
				rt=0;
			}
			else if(dt[i]+dt[i-1]+dt[i-2]==d)
			{
				ans+=lt;
				lt=rt=0;
			}
			else
			{
				if(i==3)rt+=2;
				rt++;
			}
		}
		if(qf)ans+=lt*rt;
		printf("%lld\n",ans);
	}
	return 0;
}
