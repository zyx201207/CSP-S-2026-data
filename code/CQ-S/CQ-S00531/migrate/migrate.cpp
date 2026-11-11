#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,l[N],r[N];
ll x[N],d,s1[N],s2[N],t1[N],t2[N],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			s1[i]=0;
			s2[i]=0;
			t1[i]=0;
			t2[i]=0;
		}
		r[0]=1;
		for(int i=1;i<=n;i++)
		{
			r[i]=r[i-1];
			while(r[i]<n&&x[r[i]+1]-x[i]<=d)
			{
				r[i]++;
			}
			if(r[i]>i)
			{
				s1[r[i]]++;
			}
		}
		l[n+1]=n;
		for(int i=n;i>=1;i--)
		{
			l[i]=l[i+1];
			while(l[i]>1&&x[i]-x[l[i]-1]<=d)
			{
				l[i]--;
			}
			if(l[i]<i)
			{
				s2[l[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(l[i]<i&&r[l[i]]==i)
			{
				s1[i]+=s1[l[i]];
			}
			t1[r[i]]+=(r[i]-1>i);
		}
		for(int i=n;i>=1;i--)
		{
			if(r[i]>i&&l[r[i]]==i)
			{
				s2[i]+=s2[r[i]];
			}
			t2[l[i]]+=(l[i]+1<i);
		}
		for(int i=1;i<n;i++)
		{
			int nl=l[i],nr=r[i+1];
			ans+=t1[i+1]*t2[i];
			if(l[nr]==i)
			{
				ans+=t1[i+1]*s2[nr];
			}
			if(r[nl]==i+1)
			{
				ans+=t2[i]*s1[nl];
			}
			if(nl==l[i+1]&&r[i]==nr&&l[nr]==i&&r[nl]==i+1)
			{
				ans+=s1[nl]*s2[nr];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
