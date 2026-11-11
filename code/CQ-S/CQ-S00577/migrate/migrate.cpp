#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int f[2000005];
int g[2000005];
int b[5005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int sid,T,n;
	long long d;
	scanf("%d%d",&sid,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n<=2)
		{
			printf("0\n");
			continue;
		}
		if(sid<=10)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				f[i]=0,g[i]=1;
				for(int j=0;j<=n-i+1;j++)b[j]=0;
				b[0]=1;
				for(int j=i+1,k=i;j<=n;j++)
				{
					while(k<j&&a[j]-a[k]>d)b[f[k]]-=g[k],k++;
					f[j]=f[k]+1;
					g[j]=min(3,b[f[k]]);
					b[f[j]]+=g[j];
					if(g[j]==2)ans++;
					if(g[j]==0)break;
				}
			}
			printf("%d\n",ans);
			continue;
		}
		if(sid==11||sid==12)
		{
			f[1]=0,g[1]=1;
			int cnt=0,b=n-1;
			if(d/(a[2]-a[1])<b)b=d/(a[2]-a[1]);
			for(int i=2,j=1;i<=n;i++)
			{
				if(i>b)f[i]=f[i-b]+1;
				else f[i]=1;
				while(j<i&&f[j]==f[max(1,i-b)])cnt+=g[j++];
				if(i>b)cnt-=g[i-b-1];
				g[i]=min(cnt,3);
			}
			for(int i=1;i<=n;i++)
			{
				if(g[i]==2)f[i]=f[i-1]+1;
				else f[i]=f[i-1];
			}
			long long ans=0;
			for(int i=1;i<=n;i++)ans+=f[n-i+1];
			printf("%lld\n",ans);
			continue;
		}
		if(sid==13||sid==14)
		{
			long long ans=0;
			for(int i=1,j=1,k=1,l=1;i<=n;i++)
			{
				while(j<=n&&a[j]-a[i]<=d)j++;
				if(j>n)break;
				if(i>=j-2)continue;
				k=max(k,j-2);
				while(k<=n&&a[k]-a[j-2]<=d)k++;
				l=max(l,j-3);
				while(l<=n&&a[l]-a[j-3]<=d)l++;
				ans+=k-max(j,l);
				//cout<<i<<' '<<k<<' '<<max(j,l)<<'\n';
			}
			printf("%lld\n",ans);
			continue;
		}
		int ans=0,tot=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=0,g[i]=1;
			for(int j=0;j<=tot;j++)b[j]=0;
			b[0]=1;
			for(int j=i+1,k=i;j<=n;j++)
			{
				while(k<j&&a[j]-a[k]>d)b[f[k]]-=g[k],k++;
				tot=f[j]=f[k]+1;
				g[j]=min(3,b[f[k]]);
				b[f[j]]+=g[j];
				if(g[j]==2)ans++;
				if(g[j]==0)break;
			}
		}
		printf("%d\n",ans);
	}
}
/*
13 2
10 20
1 5 8 9 15 26 35 38 39 40
15 50
1 18 30 48 49 58 67 69 71 75 84 89 91 94 97

5
5
*/
