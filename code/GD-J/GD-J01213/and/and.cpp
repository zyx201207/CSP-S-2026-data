#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
const ll N=2e5+5;
ll n,s=(1<<30)-1,m,w[35],f,l,q;
struct xx
{
	ll a,s[35],b,f;
}a[N];
void S(ll x)
{
	if(w[x]>=m)
	{
		fo(i,1,n)if(!a[i].s[x])a[i].f=0;
		fo(i,0,30)w[i]=0;
		fo(i,1,n)if(a[i].f)fo(j,0,30)w[j]+=a[i].s[j];
	}
}
bool cmp(xx x,xx y)
{
	return x.b>y.b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n)
	{
		cin>>a[i].a;
		a[i].b=a[i].a;
		fo(j,0,29)
		{
			a[i].s[j]=a[i].a&1;
			a[i].a>>=1;
			w[j]+=a[i].s[j];
		}
		a[i].f=1;
	}
	fd(i,30,0)
	{
		S(i);
//		fo(i,1,n)cout<<a[i].f<<" ";cout<<endl;
	}
	sort(a+1,a+n+1,cmp);
	while(l<=n&&m)
	{
		if(a[l].f)
		{
			s&=a[l].b;
			m--;
		}
		l++;
	}
	cout<<s<<endl;
}
