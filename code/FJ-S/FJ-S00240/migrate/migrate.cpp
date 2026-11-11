#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll c,n,d,a[N],ans,t,b[505][505],e[505],res;
bool v[505];
ll ef1(ll p)
{
	ll l=0,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(a[mid]<=p)
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
ll ef2(ll p)
{
	ll l=0,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(a[mid]>=p)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
ll ef3(ll p)
{
	ll l=0,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(a[mid]>p)
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
void dfs(ll s,ll t,ll p)
{
	if(p==b[s][t])
	{
		e[++p]=t;
//		for(int i=1;i<=p;i++)
//		{
//			cout<<e[i]<<" ";
//		}
//		cout<<endl;
		res++;
		return ;
	}
	for(int i=e[p]+1;i<t;i++)
	{
		if(a[i]-a[e[p]]>d)
		{
			break;
		}
		if(!v[i]&&a[i]-a[e[p]]<=d)
		{
			v[i]=1;
			e[p+1]=i;
			dfs(s,t,p+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ll f=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>2)
			{
				if(!(a[i]-a[i-1]==a[i-1]-a[i-2]))
				{
					f=1;
				}
			}
		}
		if(!f)
		{
			ll p=a[2]-a[1];
			ll ans=0;
			ll p1=d/p;
			if(d<2*p)
			{
				cout<<0<<"\n";
				continue;
			}
			for(int i=1;i<=n;i++)
			{
//				cout<<i<<" ";
				if(a[i]+2ll*p1*p-p<=a[n])
				{
					ans++;
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(n<=9)
		{
			res=0;
			ll ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					b[i][j]=1e18;
				}
			}
			for(int i=1;i<=n;i++)
			{
				b[i][i]=0;
				for(int j=i+1;j<=n;j++)
				{
					if(a[i]+d<a[j])
					{
						break;
					}
					b[i][j]=b[j][i]=1;
				}
			}
			for(int len=1;len<=n;len++)
			{
				for(int i=1;i+len-1<=n;i++)
				{
					int j=i+len-1;
					ll res=b[i][j];
					for(int k=i+1;k<j;k++)
					{
						b[j][i]=b[i][j]=min(b[i][j],b[i][k]+b[j][k]);
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(b[i][j]==1||b[i][j]==1e18)
					{
						continue;
					}
					res=0;
					e[1]=i;
					dfs(i,j,1);
					if(res==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
			continue;
		}
//		cout<<l<<" "<<r<<"\n";
		ll r=ef1(a[1]+d);
		ll l=ef2(a[n]-d);
		if(l<=r)
		{
			if(r-l+1>2)
			{
				cout<<"0\n";
				continue;
			}
			ll l1=l,r1=r;
			ll ans=n-r;
			for(ll i=2;i<l;i++)
			{
				l1=max(l1,i);
				r1=max(r1,ef3(d+a[i]));
				if(r1-l1+1>2)
				{
					continue;
				}
				ans+=n-r;
			}
			cout<<ans<<"\n";
			continue;
		}
		else
		{
			cout<<"0\n";
		}
	}
	return 0;
}
