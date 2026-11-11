#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
const ll N=5e5+5,M=3e5+5;
int n,m,ans[M],la,s,t;
struct xx{ll a,f;}a[N];
struct yy{ll l,s;}b[M];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n)
	{
		cin>>a[i].a;
		b[a[i].a].l=i;
	}
	fo(i,1,n)
	{
		int j=i;
		while(j<=n)
		{
			ans[a[j].a]++;
			j=b[a[j].a].l;
			j++;
		}
	}
	fo(i,1,m-1)cout<<ans[i]<<" ";cout<<ans[m]<<endl;
}
