#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<n;i++)
		{
			int p1=0,p2=0,fl=0;
			for(int j=i+2;j<n&&x[j]-x[i]<=d;j++) p1=j;
			if(p1==0) continue;
			for(int j=p1+1;j<=n&&x[j]-x[p1-1]<=d&&x[j]-x[i]>d;j++) p2=j;
			if(p2==0) continue;
			for(int j=i+1;j<p1;j++)
				if(x[j]-x[i]<=d&&x[p2]-x[j]<=d) fl++;
	//		cout<<p1<<" "<<p2<<"\n";
			if(fl>1) continue;
			ans++;
			for(int j=p2+1;j<=n&&(x[j]-x[p1]>d||(x[j]-x[p1]<=d&&x[j]-x[p1-1]<=d))&&x[j]-x[j-1]<=d;j++) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
