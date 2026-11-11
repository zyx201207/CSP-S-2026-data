#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,a[N],ans,tot,kpl,b[N],num,pop=LLONG_MIN,lkl=LLONG_MAX;
bool f=false;
ll dfs(ll x)
{
	ll op=0,sum=m,lpl=1;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(a[i]-x);
	}
	sort(b+1,b+n+1);
	while(sum-b[lpl]>=0)
	{
		op++;
		sum-=b[lpl];
		lpl++;
	}
	return op;
}
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			num++;
		}
		lkl=min(lkl,a[i]);
		pop=max(pop,a[i]);
	}
	tot=a[2]-a[1];
	for(int i=3;i<=n;i++)
	{
		if(tot!=a[i]-a[i-1])
		{
			f=true;
			break;
		}
	}
	if(num==n)
	{
		sort(a+1,a+n+1,cmp);
		ans=1;
		for(int i=1;i<=n;i++)
		{
			if(m<i)
			{
				break;
			}
			else
			{
				ans++;
				m-=i;
			}
		}
		cout<<ans;
		return 0;
	}
	if(!f)
	{
		sort(a+1,a+n+1,cmp);
		ans=1;
		kpl=tot;
		while(m-kpl>=0)
		{
			ans++;
			m-=kpl;
			kpl+=tot;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=lkl;i<=pop;i++)
	{
		ans=max(ans,dfs(i));
	}
	cout<<ans;
	return 0;
}
