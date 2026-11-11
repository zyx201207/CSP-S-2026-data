#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,dp[N];
long long d,x[N],val[N],sum[N];
void solve()
{
	long long ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++) dp[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i+1]-x[i]>d) continue ;
		for(int j=i+2;j<=n;j++)
		{
			if(x[j]-x[i]>d) dp[i]=j-1;
		}
		if(!dp[i]) dp[i]=n;
	}

	for(int i=1;i<=n;i++)
	{
		int pos=i+1,last;
		
		vector<int> f;
		
		if(x[pos]-x[i]>d) continue ;
		
		while(pos<=n && x[pos]-x[i]<=d) last=pos,pos++;
		
		f.push_back(last);
		
		for(;pos<=n;pos++)
		{
			if(x[pos]-x[pos-1]>d) break ;
			
			if(x[pos]-x[last]>d) last=pos-1,f.push_back(pos-1);
			
			int len=f.size(),l=pos,r=pos;
			val[pos]=1;
			for(int j=len-1;j>=0;j--)
			{
				int now=f[j];
				sum[now]=0;
				for(int k=l;k<=r;k++) sum[k]=sum[k-1]+val[k];
				while(dp[now]>=l)
				{
					val[now]=sum[min(r,dp[now])]-sum[l-1];
					if(now==i+1 || now==f[j-1]+1) break ;
					now--;
					
				}
				l=now,r=f[j];
			}
			sum[i]=0;
			for(int k=l;k<=r;k++) sum[k]=sum[k-1]+val[k];
			long long d=sum[r]-sum[l-1]; 
			for(int j=i;j<=pos;j++) val[j]=0,sum[j]=0;
			ans+=(d==2);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve(); 
	
	return 0;
}
