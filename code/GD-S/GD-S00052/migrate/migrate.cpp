#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[20005],ans,jy[20005];
long long lf,rf,l,r,mid,lp,rp;
vector<long long>yd[20005];
long long dfs(long long x,long long fa)
{
	if(jy[x]!=0) return jy[x];
	long long sum=1;
	for(long long i=0;i<yd[x].size();i++) if(yd[x][i]!=fa) sum+=dfs(yd[x][i],x);
	jy[x]=sum;
	return sum;
}
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(jy,0,sizeof jy);
		cin>>n>>d;
		for(long long i=0;i<n;i++) yd[i].clear();
		for(long long i=1;i<=n;i++) cin>>a[i];
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				lf=a[j]-d,rf=a[i]+d;
				if(lf>=rf||lf>=a[j]||rf<=a[i]||lf<a[1]||rf>a[n]) continue;
				l=0,r=n+1;
				while(l+1<r)
				{
					mid=(l+r)>>1;
					if(a[mid]<lf) l=mid; 
					else r=mid;
				}
				lp=r;
				l=0,r=n+1;
				while(l+1<r)
				{
					mid=(l+r)>>1;
					if(a[mid]<=rf) l=mid; 
					else r=mid;
				}
				rp=r-1;
				if(rp==lp) yd[i].push_back(j),yd[j].push_back(i);
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				lf=a[j]-d,rf=a[i]+d;
				if(lf>=rf||lf>=a[j]||rf<=a[i]||lf<a[1]||rf>a[n]) continue;
				l=0,r=n+1;
				while(l+1<r)
				{
					mid=(l+r)>>1;
					if(a[mid]<lf) l=mid; 
					else r=mid;
				}
				lp=r;
				l=0,r=n+1;
				while(l+1<r)
				{
					mid=(l+r)>>1;
					if(a[mid]<=rf) l=mid; 
					else r=mid;
				}
				rp=r-1;
//				cout<<i<<" "<<j<<"  "<<lf<<" "<<rf<<"  "<<lp<<" "<<rp<<"\n";
				if(rp-lp==1) ans+=dfs(i,0)*dfs(j,0);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
2 5
2 6
3 7
4 7

1 3

0 1
7 6
-10 -5 -1 1 3 5 9
*/
