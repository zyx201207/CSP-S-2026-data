#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
struct Node{
	ll v,as;
}a[N];
ll n,m,b,maxn=-1e9,ans=0;
bool klk=true;
bool cmp(const Node &x,const Node &y)
{
	if(x.as!=y.as)		return x.as>y.as;
	else 				return x.v>y.v;
}
void solve()
{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-m;i++)
	{
		bool ln=true;
		for(int j=i;j<i+m;j++)
		{
			if(a[j].as!=a[j+1].as)		
			{
				ln=false;
				break;
			}
		}
		ans=a[i].v;
		if(ln==false)
		{
			continue;
		}
		else
		{
			for(int j=i+1;j<i+m;j++)
			{
				ans&=a[j].v;
			}
		}
		return ;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&a[1].v);
	b=a[1].v;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i].v);
		a[i].as=log2(a[i].v);
		if(b!=a[i].v)
			klk=false;
		b=a[i].v;
	}
	if(klk)
	{
		printf("%lld",b);
	}
	else
	{
		solve();
		printf("%lld",ans);
	}
	return 0;
}
