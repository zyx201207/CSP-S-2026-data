#include<bits/stdc++.h>
using namespace std;
long long C,T,n,D,an,a[2000005];
long long d[2000005],f[2000005],dd[2000005],ff[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>D;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		d[n]=n+1,f[n]=0;
		for(int i=n-1,l,r,mid,L,R;i>=1;i--)
		{
			l=i+1,r=n;
			while(l<r)
			{
				mid=(l+r+1)>>1;
				if(a[mid]-a[i]<=D)l=mid;
				else r=mid-1;
			}
			d[i]=l;
			if(a[l]-a[i]>D)f[i]=0;
			else if(d[l-1]==d[l])f[i]=1;
			else
			{
				f[i]=f[l];
			L=l+1,R=d[l];
			while(L<R)
			{
				mid=(L+R+1)>>1;
				if(a[mid]-a[l-1]>D)L=mid;
				else R=mid-1;
			}
//				if(a[l+1]-a[l-1]>D)
				f[i]+=L-l;
//				f[i]=f[l]+d[l]-l;
			}
		}
		dd[1]=ff[1]=0;
		for(int i=2,l,r,mid,L,R;i<=n;i++)
		{
			l=1,r=i-1;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(a[i]-a[mid]<=D)r=mid;
				else l=mid+1;
			}
			dd[i]=l;
			if(a[i]-a[l]>D)ff[i]=0;
			else if(dd[l]==dd[l+1])ff[i]=1;
			else
			{
				ff[i]=ff[l];
			L=dd[l],R=l-1;
			while(L<R)
			{
				mid=(L+R)>>1;
				if(a[l+1]-a[mid]>D)R=mid;
				else L=mid+1;
			}
//				if(a[l+1]-a[l-1]>D)
				ff[i]+=l-L;
//				if(L!=dd[l])cout<<L<<' '<<dd[l]<<" "<<a[l+1]-a[1]<<' '<<D<<' '<<a[l+1]-a[L]<<'\n';
//				ff[i]=ff[l]+l-dd[l];
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<f[i]<<' ';
//		}
//		cout<<'\n';
//		for(int i=1;i<=n;i++)
//		{
//			cout<<ff[i]<<' ';
//		}
//		cout<<'\n';
//		for(int i=1;i<=n;i++)
//		{
//			cout<<d[i]<<' ';
//		}
//		cout<<'\n';
//		for(int i=1;i<=n;i++)
//		{
//			cout<<dd[i]<<' ';
//		}
//		cout<<'\n';
//cout<<d[1]<<' '<<d[99992]<<' '<<d[99993]<<'\n';
		an=0;
		for(int i=2;i+1<n;i++)
		{
//			if(i==99992)
//			{
//			cout<<i<<' '<<i+1<<' '<<d[i]<<' '<<d[i+1]<<" "<<dd[i]<<' '<<dd[i+1]<<' '<<ff[i]<<' '<<f[i+1]<<' '<<an<<'\n';
//			cout<<"         "<<d[i-1]<<' '<<dd[i+2]<<' '<<(dd[i+2]-dd[i+1])<<' '<<(d[i]-d[i-1])<<'\n';
//			}
			if(dd[i+1]==dd[i+2]||d[i]==d[i-1]||d[i]==i+1||dd[i+1]==i)continue;
			if(a[d[i+1]]-a[i+1]>D||a[d[i]]-a[i]>D)continue;
			if(a[i]-a[dd[i]]>D||a[i+1]-a[dd[i+1]]>D)continue;
			if(d[i]==d[i+1]&&dd[i]==dd[i+1])an+=ff[i]*f[i+1]+f[i+1]*(dd[i+2]-dd[i+1]-1)+ff[i]*(d[i]-d[i-1]-1)+(dd[i+2]-dd[i+1]-1)*(d[i]-d[i-1]-1);
			else if(d[i]==d[i+1])an+=f[i+1]*(dd[i+2]-dd[i+1])+(dd[i+2]-dd[i+1])*(d[i]-d[i-1]-1);
			else if(dd[i]==dd[i+1])an+=ff[i]*(d[i]-d[i-1])+(dd[i+2]-dd[i+1]-1)*(d[i]-d[i-1]);
			else an+=(dd[i+2]-dd[i+1])*(d[i]-d[i-1]);
//			cout<<i<<' '<<i+1<<' '<<d[i]<<' '<<d[i+1]<<" "<<dd[i]<<' '<<dd[i+1]<<' '<<ff[i]<<' '<<f[i+1]<<' '<<an<<'\n';
//			cout<<"         "<<d[i-1]<<' '<<dd[i+2]<<' '<<(dd[i+2]-dd[i+1])<<' '<<(d[i]-d[i-1])<<'\n';
		}
//		cout<<'\n';
//		cout<<n<<' '<<n*n<<' ';
		cout<<an<<'\n';
	}
	return 0;
}
