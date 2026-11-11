#include<bits/stdc++.h>
using namespace std;
#define i1 __int128
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
const ll N=5e5+5;
ll a[N],s,m,n;
i1 l,r,mi;
bool pd(i1 x)
{
	i1 s=0;
	fo(i,1,x)s+=a[x]-a[i];
	if(s<=m)return 1;
	fo(i,x+1,n)
	{
		s-=a[i-1]-a[i-x];
		s+=x*(a[i]-a[i-1]);
		if(s<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;r=n;
	while(l<=r)
	{
		mi=l+r>>1;
		if(pd(mi))l=mi+1,s=mi;
		else r=mi-1;
	}
	cout<<s<<endl;
}
