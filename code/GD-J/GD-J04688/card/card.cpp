#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<=n;++i)
const int maxn=5e5+10;
ll n,m,a[maxn],num[maxn];
map<ll,ll> b;
map<ll,ll> ans;
void sol()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)
	{
		rep(j,i,n)
		{
			if(b[a[j]])
			{
				rep(p,num[a[j]],j)b[a[p]]=0;
				num[a[j]]=j;
			}
			else 
			{
				b[a[j]]=1;
				num[a[j]]=j;
			}
		}
		rep(o,i,n)if(b[a[o]])ans[a[o]]++;
		for(auto x:b)cout<<x.second<<' ';
		cout<<endl;
		rep(i,1,n)b[i]=0,num[i]=0;
	}
	for(auto x:ans)cout<<x.second<<' ';
}
int main()
{
	sol();
	return 0;
}
