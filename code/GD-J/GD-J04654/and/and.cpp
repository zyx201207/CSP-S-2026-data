#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+10;
ll n,m,a[N],f[43],ans,s[N],l[N],p,lp; 
vector<ll> e[43];
void deal(ll t)
{
	ll s=0,p=t;
	while(t)
	{
		if(t&1)
		{
			f[s]++;
			e[s].push_back(p);
		} 
		t>>=1;
		s++;
	}
}
void find(ll t)
{
	ans+=((ll)1<<t);
	for(auto u:e[t])
		s[++p]=u;
//	memcpy(l,s,sizeof(s));
//	lp=p;
	for(int i=t-1;i>=0;i--)
	{
		memset(l,0,sizeof(l));
		lp=0;
		for(int j=1;j<=p;j++)
			if(s[j]&((ll)1<<i))
				l[++lp]=s[j];
		if(lp>=m)
		{
			ans+=((ll)1<<i);
			memcpy(s,l,sizeof(l));
			p=lp;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		deal(a[i]);
	}
	for(int i=32;i>=0;i--)
		if(f[i]>=m)
		{
//			cout<<i;
			find(i);
			break;
		}
	cout<<ans;
	return 0;
}
