#include<bits/stdc++.h>
#define ll long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define itn int
#define asn ans
using namespace std;
ll n,m,idx;
const ll N=5e5+5;
ll a[N],b[N];
vector<ll>z;
void put(ll x)
{
	for(int i=1;i<=idx;i++)
	{
		if(z[i]==x)
		{
			int l=i;
			int r=idx;
			for(;l<r;l++)
			{
				z[l]=0;
			}
		}
	}
	z[idx]=x;
}
int main()
{
	fre("card");
	cin>>n>>m;
	cin.tie(nullptr);
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll j=1;j<=n;j++)
	{
		put(a[j]);
		for(ll i=1;i<=z.empty();i++)
		{
			if(z[i]==j)b[j]++;
		}
	}
	for(ll i=1;i<=m;i++)cout<<b[i]<<" ";
    return 0;
}
