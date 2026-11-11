#include<bits/stdc++.h>
using namespace std;
long long tsq;
long long n,d;
long long a[2000001];
int t,c;
long long ans;
int vis[2000001],vis1[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		long long sum=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) vis[i]=0,vis1[i]=0;
		for(int i=1;i<n;i++) if(a[i+1]-a[i]>d) vis1[i]=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i+3]-a[i]<=d) continue;
			if(a[i+2]-a[i]>d||a[i+3]-a[i+1]>d) continue;
			vis[i]=1;
		}
		ans=0;
		for(int i=1;i<=n-3;i++)
		{
			if(vis[i]==1) {
				long long sum1=i,sum2=(n-i-2);
				for(int j=i-1;j>=1;j--) {
					if(vis1[j]==1) {
						sum1=i-j;
					}
					else if(vis[j]==1) {
						sum1=i-j;
						break;
					}
				}
				for(int j=i+4;j<=n;j++) {
					if(vis1[j]==1) {
						sum2=j-(i+3)+1;
					}
					else if(vis[j]==1) {
						sum2=j-i;
						break;
					}	
				}
				ans=ans+sum1*sum2;	
			}
		}
		printf("%lld\n",ans);
	}
}
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/

