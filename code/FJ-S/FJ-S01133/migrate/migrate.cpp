#include<bits/stdc++.h> 
using namespace std;
long long f[305][305],c,t,a[2000006],d;
bool pd=1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(;t--;)
	{
		long long n,ans=0;
		scanf("%lld%lld",&n,&d);
	//	cout<<1;
	//	cout<<n<<" "<<d<<endl;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) pd=0;
		}
		if(pd)
		{
		//	cout<<(d/(a[n]-a[n-1])*2-1)<<endl;
			if(a[n]*2-a[n-1]*2>d||n<d/(a[n]-a[n-1])*2) cout<<0<<endl;
			else cout<<n-(d/(a[n]-a[n-1])*2)+1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int o=i+1;o<=n;o++)
			{
				int js=1,p=i;
				for(int j=i+1;j<=o;j++)
				{
					if(a[j]-a[j-1]>d) 
					{
						js=n+1;
						break;
					}
					if(a[j]-a[p]<=d) continue;
					js++;
					p=j-1;
				}
				f[i][o]=js;
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int o=i+2;o<=n;o++)
			{
				if(f[i][o]==1) continue;
				int js=1,p=i;
				for(int j=i+1;j<=o;j++)
				{
					if(a[j]-a[p]<=d) continue;
					for(int k=j-2;k>p;k--)
					{
						if(f[i][k]+f[k][o]==f[i][o]) js++;
					}
					p=j-1;
				}
				if(js==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
*/
