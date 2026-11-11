#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,a[2000005],L[2000005],R[2000005],ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=5000)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ll l=i,r=n;
				while(l<=r)
				{
					ll mid=(l+r)>>1;
					if(a[mid]-a[i]>d) r=mid-1;
					else l=mid+1;
				}
				R[i]=l-1;
				l=1;r=i;
				while(l<=r)
				{
					ll mid=(l+r)>>1;
					if(a[i]-a[mid]>d) l=mid+1;
					else r=mid-1;
				}
				L[i]=r+1;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					ll pos=i,len=0,bz=true;
					while(1)
					{
						if(pos==R[pos])
						{
							bz=false;
							break;
						}
						pos=R[pos];
						len++;
						if(pos>=j) break;
					}
					if(bz==false) continue;
					ll sum=0;
					queue<pair<ll,ll>> q;
					q.push({i,0});
					while(!q.empty())
					{
						ll u=q.front().first,stp=q.front().second;
						q.pop();
						if(u==j&&stp==len)
						{
							sum++;
							if(sum>2) break;
							continue;
						}
						for(int k=u+1;k<=R[u];k++) if(stp+1<=len) q.push({k,stp+1});
						for(int k=L[u];k<=u-1;k++) if(stp+1<=len) q.push({k,stp+1});
					}
					if(sum==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
		else printf("0\n");
	}
	return 0;
}
