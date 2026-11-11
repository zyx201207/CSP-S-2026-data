#include<bits/stdc++.h>
#define mid (l+r+1>>1)
#define ll long long
#define N 2000100
using namespace std;
int n,c,_;
ll k,ans;
ll a[N],dis[51000],cnt[51000];
deque<int>q;
deque<int>ve[51000];
ll read()
{
	char tmp;
	ll flag=1;
	while((tmp=getchar())<'0'||tmp>'9')
		if(tmp=='-')
			flag=-1;
	ll ans=tmp-'0';
	while((tmp=getchar())>='0'&&tmp<='9')
		ans=ans*10+tmp-'0';
	return ans*flag;
}
void solvebelow10()
{
	ans=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		ve[i].clear();
		for(int j=1;j<i;j++)
			if(a[i]-a[j]<=k)
				ve[i].push_back(j);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i]=0;
		cnt[i]=1;
		for(int j=i+1;j<=n;j++)
		{
			dis[j]=1e9;
			cnt[j]=0;
			if(ve[j].size()&&ve[j].front()<i)
				ve[j].pop_front();
		}
		for(int j=i+1;j<=n;j++)
		{
			if(!ve[j].size())
				break;
			dis[j]=dis[ve[j].front()]+1;
			for(auto &v:ve[j])
			{
				if(dis[v]!=dis[j]-1)
					break;
				cnt[j]+=cnt[v];
				if(cnt[j]>=3)
				{
					cnt[j]=3;
					break;
				}
			}
			ans+=(cnt[j]==2);
		}
	}
	cout<<ans<<'\n';
}
void solve11and12()
{
	n=read();
	k=read();
	ll x1=read(),x2;
	if(n==1)
	{
		puts("0");
		return;
	}
	x2=read();
	ll d=k/(x2-x1);
	for(int i=3;i<=n;i++)
		x2=read();
	if(d<=1)
	{
		puts("0");
		return;
	}
	cout<<max(0ll,n-2*d+1)<<'\n';
}
void solve13and14()
{
	ans=0;
	n=read();
	k=read();
	a[0]=-4e18;
	while(q.size())
		q.pop_back();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int j=1;j<=n;j++)
	{
		while(q.size()&&a[q.front()]+k<a[j])
			q.pop_front();
		if(q.size()<=2)
		{
			if(q.size()==2)
			{
				int l=0,r=j-2;
				while(l<r)
				{
					if(a[j-1]-a[mid]<=k)
						r=mid-1;
					else
						l=mid;
				}
				ans+=max(0,j-3-r);
			}
			q.push_back(j);
			continue;
		}
		ll tmp=q[2];
		int l=1,r=q[0]-1;
		while(l<r)
		{
			if(a[tmp]-a[mid]<=k)
				r=mid-1;
			else
				l=mid;
		}
		ans+=r;
		q.push_back(j);
	}
	cout<<ans<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	_=read();
	if(c>=11&&c<=12)
	{
		while(_--)
			solve11and12();
	}
	else if(c>=13&&c<=14)
	{
		while(_--)
			solve13and14();
	}
	else
	{
		while(_--)
			solvebelow10();
	}
	return 0;
}
