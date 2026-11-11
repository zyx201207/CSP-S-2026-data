#include<bits/stdc++.h>
using namespace std;
long long c,T,n;
long long d;
long long x[2000005];
long long ll[2000005];
long long rr[2000005];
long long l_[2000005];
long long r_[2000005];
long long far[2000005];
long long raf[2000005];
int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		long long i,j;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
			l_[i]=r_[i]=i;
			ll[i]=rr[i]=0;
			far[i]=raf[i]=0;
		}
		long long l,r;
		r=0;
		for(l=1;l<=n;l++)
		{
			long long nr=max(l,r);
			while(nr<n&&x[nr+1]-x[l]<=d)
			{
				nr++;
			}
			r_[l]=nr;
			far[nr]++;
			r=nr;
		}
		l=n+1;
		for(r=n;r>=1;r--)
		{
			long long nl=min(l,r);
			while(nl>1&&x[r]-x[nl-1]<=d)
			{
				nl--;
			}
			l_[r]=nl;
			raf[nl]++;
			l=nl;
		}
		for(i=1;i<=n;i++)
		{
			if(l_[i]==i)
			{
				ll[i]=1;
				continue;
			}
			if(r_[l_[i]]==i)
			{
				ll[i]=ll[l_[i]]+(far[i]-1)+1;
				continue;
			}
			ll[i]=far[i]+1;
		}
		for(i=n;i>=1;i--)
		{
			if(r_[i]==i)
			{
				rr[i]=1;
				continue;
			}
			if(l_[r_[i]]==i)
			{
				rr[i]=rr[r_[i]]+(raf[i]-1)+1;
				continue;
			}
			rr[i]=raf[i]+1;
		}
		long long ans=0;
		for(i=1;i<n;i++)
		{
			if(l_[i+1]<i&&r_[i]>i+1)
			{
				ans+=(ll[i+1]-1ll)*(rr[i]-1ll);
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

